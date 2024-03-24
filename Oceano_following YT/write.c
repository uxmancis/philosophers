/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:28:43 by uxmancis          #+#    #+#             */
/*   Updated: 2024/03/24 16:57:47 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*   [time_ms][philo_id][action]
*
*   thread safe
*   write mutex
*/
void write_status(t_philo_status status, t_philo *philo, bool debug)
{
    long elapsed;

    elapsed = gettime(MILLISECOND);

    if(philo->full)
        return;

    //🔒lock
    if(debug)
        write_status_debug(status, philo, elapsed);
    else
    {
        safe_mutex_handle(&philo->table->write_mutex, LOCK);
        if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK)
            && !simulation_finished(philo->table))
            printf(W"%-6LD"RST" %d has taken a fork\n", elapsed, philo->id);
        else if (status == EATING && !simulation_finished(philo->table))
            printf(W"%-6ld"C" %d is eating\n"RST, elapsed, philo->id);
        else if (status == SLEEPING && !simulation_finished(philo->table))
            printf(W"%-6ld"RST" %d is sleeping\n", elapsed, philo->id);
        else if (status == THINKING && !simulation_finished(philo->table))
            printf(W"%-6ld"RST" %d is thinking\n", elapsed, philo->id);
        else if (status == DIED)
            printf(RED"%-6ld %d died\n"RST, elapsed, philo->id);
    }
    //🔓unlock
    safe_mutex_handle(&philo->table->write_mutex, UNLOCK);
}
