/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:35:21 by uxmancis          #+#    #+#             */
/*   Updated: 2024/03/23 19:01:05 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*DESCRITION
*	philosophers project aims us to learn about threads, a fundamental 
*	concept in programming concurrency.
*
*	Threads in programming refer to the smallest unit of execution
*	within a process. They are independent paths of execution
*	that can run concurrently (at the same time) within a single process. 
*	Threads share the same memory space and resources of the process 
*	they belong to, enabling them to communicate and share data efficiently.
*
*	philosophers program makes x philosophers (threads) carry out their
*	daily routine (eat, sleep, think). The philosophers (threads) share
*	forks for eating. Which means a philosopher (thread) must wait for another
*	philosopher (thread) to finish eating so that the fork is free in order
*	to start eating.
*	
*	Mutex will have to be used to avoid data races. Race conditioons are
*	intra-process (threads level, sharing same memory), not inter-processes.
*
*	Deadlocks happen when all threads are locked to proceed their execution,
*	as all of them are waiting for the other thread to free the shared
*	resource (as they share memory).
*------------------------------------------------------------------------------*/
int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 5 && argc != 6) //synonym: if (!(argc == 5 || argc== 6))
	{
		putmessage();
		return (0);
	}
	else if (argc == 5 || argc == 6)
	{
		if (check_digits(argc, argv) == 0)
		{
			putmessage2();
			return (0);
		}
		if (exec_philo(argc, argv) == 1)
		{
			putmessage3();
			return (0);
		}
	}

	if (argc == 5 || argc == 6)
	{
		if (check_error(argc, argv) == 0) //ondo
		{
				//2. initialize and create everyting
				//3. dinner
				//4. clean leaks function: either philos are full || or 1 philo died
		}
		else
			return (0);
	}
	else
		putmessage();
	return (0);
	/*else if (argc == 5) Idea feliz, cómo dejar proceso abierto y que user me pueda decir Y/N, como en el grademe
	{
		write(1, "Would you also like to add 5th argument, ", 41);
		write(1, "number_of_times_each_philosopher_must_eat, (Optional)?\n", 56);
		write(1, "[Y/N]?\n", 7);
		while(1)
		{
			if (argv[1][0] == 'Y')
				write(1, "yes\n", 4);
			else if (argv[1][0] == 'N')
				write(1, "no\n", 3);
			write(1, "yep", 3);
		}
	}*/
	return (0);
}
