/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:30:05 by uxmancis          #+#    #+#             */
/*   Updated: 2024/03/24 17:14:53 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void thinking(t_philo *philo)
{
    write_status(THINKING, philo, DEBUG_MODE);
}

/*eat routine
*
*   1) grab the forkss: first and second fork is handy
        don't worry about left right
    2) eat: write eat, update last meal, update meals counter
        eventually bool full
    3) release the forks
*/
static void eat(t_philo *philo)
{
    //1) 
    safe_mutex_handle(&philo->first_fork->fork, LOCK);
    write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
    safe_mutex_handle(&philo->second_fork->fork, LOCK);
    write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);

    //2
    set_long(&philo->last_meal_time, gettime(MILLISECOND));
    philo->meals_counter++;
    write_status(EATING, philo, DEBUG_MODE);
    precise_usleep(philo->table->time_to_eat, philo->table);
    if(philo->table->nbr_limit_meals > 0
        && philo->meals_counter == philo->table->nbr_limit_meals)
        set_bool(&philo->philo_mutex, &philo->full, true);
    //3
    safe_mutex_handle(&philo->first_fork->fork, UNLOCK);
    safe_mutex_handle(&philo->second_fork->fork, UNLOCK);
}

/*
*   0) wait all philos, synchro starts

*/
void *dinner_simulation(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    wait_all_threads(philo->table);
    
    //set last meal time
    while (!simulation_finished(philo->table))
    {
        //1. am i full?
        if (philo->full) //TODO thread safe?
            break;
        //2. eat
        eat(philo);
        //3. sleep --> write status + precise usleep
        write_status(SLEEPING, philo, DEBUG_MODE);
        precise_usleep(philo->table->time_to_sleep, philo->table);
        
        //4. think
        thinking(philo); //TODO
    }
    return (NULL);
}


/*
*   0) If no meals --> return 0
*   0.1) If only 1 phlo --> ad hoc function
*   1) Create all threads, all philos
*   2) Create a monitor thread --> looking for dead philosophers
*   3) Synchronize the beginning of the simulation
*       pthread_create-> philo starts running!
*       every philo start simultaneously
*   4) JOIN everyone
*/
void    dinner_start(t_table *table)
{
    int i; 

    i = 0;
    if(table ->nbr_limit_meals == 0)
        return; //back to main, clean
    else if (table->philo_nbr == 1)
        ;//todo
    else
    {
        while (i < table->philo_nbr)
        {
            safe_thread_handle(&table->philo_nbr[i].thread_id, dinner_simulation,
                    &table->philos[i], CREATE); //Create threads
            i++;
        }
    }
    //start of simulation, get the time! :)
    table->start_simulation = gettime(MILLISECOND);
    //now all threads are ready!
    set_bool(&table->table_mutex, &table->all_threads_ready, true);
    //wait for everyone
    i = -1
    while (i < table->philo_nbr)
    {
        safe_thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN);
        i++;
    }
    //If we manage to reach this line, all philos are full, everyone survived :)
}