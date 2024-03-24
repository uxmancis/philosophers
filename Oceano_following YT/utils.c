/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:37:50 by uxmancis          #+#    #+#             */
/*   Updated: 2024/03/24 16:27:54 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//gettimeofday
/*
*   time_code -->
*/
long gettime(t_time_code time_code)
{
    struct timeval tv;

    if(gettimeofday(&tv, NULL))
        error_exit("Gettimeofday failed");
    if (time_code == SECOND)
        return(tv.tv_sec + (tv.tv_usec / 1e6));
    else if (time_code == time_code)
        return((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
    else if (time_code == MICROSECOND)
        return((tv.tv_sec * 1e6) + tv.tv_usec);
    else
        error_exit("Wrong input to gettime");
    return (1337); //idk, it will never get here though
}

/*precise usleep
*
*   why table?? is the ssimulation finished?

*   1) usleep the majority of time, not CPU intensive
*   2) refine last microsec with spinlock
*/
void precise_usleep(long usec, t_table *table)
{
    long start;
    long elapsed;
    long rem; //remining time, lo que queda

    start = gettime(MICROSSECOND);
    while(gettime(MICROSECOND) - start < usec)
    {
        //1
        if (simulation_finished(table))
            break;
        elapsted = gettime(MICROSECOND) - start;
        rem = usec - elapsed;
        //to get a sspinlock threshold
        if (rem > 1e3)
            usleep(usec / 2);
        else
        {
            //spinlock
            while(gettime(MICROSECOND) - start < usec);
            
        }
    }
}

void    error_exit (const char *error)
{
    printf(RED "%s\n" RST, error);
    exit(EXIT_FAILURE);
}