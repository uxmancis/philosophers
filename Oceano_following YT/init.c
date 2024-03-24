/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:41:15 by uxmancis          #+#    #+#             */
/*   Updated: 2024/03/24 17:08:32 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//even-odd (par-impar) fork assignment
static void assign_forks (t_philo *philo, t_fork *forks, int position)
{
    int philo_nbr;

    philo_nbr = philo->table->philo_nbr;

    if (philo->id % 2)
    {
         philo->first_fork = &forks[philo_position];
         philo->second_fork = &forks[(philo_position + 1) % philo_nbr];
    }
   
    //potential deadlock. Oceano dice que ha encontrado 2 soluciones online: él utiliza el de threads odd/even para que cojan fork de la izq. o dcha.
    //contention points must be handled so that 1 philo gets the fork (e.g. odd) and the one next to it gets no fork at first.
}

static void philo_init(t_table *table)
{
    int i;
    t_philo *philo;

    i = -1;
    while (i < table->philo_nbr)
    {
        philo = table->philos + i;
        philo->id = i + 1;
        philo->full = false;
        philo->meals_counter = 0;
        philo->table = table;
        safe_mutex_handle(&philo->philo_mutex, INIT); //so that each philo has its own mutex
        assign_forks(philo, table->forks, i);
        i++;
    }
}

void data_init (t_table *table)
{
    int i; 
    
    table->end_simulation = false;
    table->all_threads_ready = false;
    safe_mutex_handle(table->table_mutex, INIT);
    safe_mutex_handle(table->write_mutex, INIT);
    table->philos = safe_malloc(sizeof(t_philo) * table->philo_nbr);
    table->forks = safe_malloc(sizeof(t_fork) * table->philo_nbr);
    
    i = -1;
    while (i < table->philo_nbr)
    {
        safe_mutex_handle(table->forks[i], INIT);
        table->forks[i].fork_id = i;
        i++;
    }
    philo_init(table);
}