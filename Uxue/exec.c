/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:52:00 by uxmancis          #+#    #+#             */
/*   Updated: 2024/03/23 18:54:33 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int ledger = 0;

pthread_mutex_t ledger_lock = PTHREAD_MUTEX_INITIALIZER;

void *ft_actions(void *data)
{
	(void)data;

	pthread_mutex_lock(&ledger_lock); //🔒lock
	ledger = ledger + 1; //action = critial section
	pthread_mutex_unlock(&ledger_lock); //🔓unlock
	
	//printf("ledger = %d\n", ledger);	
	//timestamp_in_ms X has taken a fork
	//timestamp_in_ms X is eating
	//timestamp_in_ms X is sleeping
	//timestamp_in_ms X is thinking
	//timestamp_in_ms X died

	//*timestamp_in_ms = tiempo actual en milisegundos
	//X = número de filósofo
	return (0);
}


/*DESCRIPTION create_philo_threads:
*	In create_philo_threads function we will create X number
*	of threads, based on the number_of_philosophers argument
*	indicated by the user when executing ./philo program.
*
*	Each philosopher will be a different thread.
*
*	pthread_create function returns a 0 when thread was
*	created correctly. When it does not return 0 means some
*	kind of error happened when creating the thread. In those
*	potential cases, our program will automatically finish.
*-----------------------------------------------------------*/
int create_philo_threads(t_args rules)
{
	int keep_number_of_philosophers;
	pthread_t philosopher[rules.number_of_philosophers];
	int i;
	//int counter;

	//counter = 0;
	i = 0;
	keep_number_of_philosophers = rules.number_of_philosophers;
	while (rules.number_of_philosophers > 0)
	{
		if (pthread_create(&philosopher[i], NULL, ft_actions, NULL) != 0) //"&philosohper[i]" sinónimo de "philosohper + i"
			return(1);
		rules.number_of_philosophers--;
		i++;  
		//counter++;
	}
	//keep_number_of_philosophers;
	/*i = 0;
	while (i < keep_number_of_philosophers)
	{
		printf("ID Philosopher (thread) = %lu\n", (unsigned long)philosopher[i]); //%lu = unsigned long int
		i++;
	}*/
	i = 0;
	while (keep_number_of_philosophers > 0)
	{
		pthread_join(philosopher[i], NULL);
		keep_number_of_philosophers--;
		i++;
	}
	printf("final ledger = %d\n", ledger);
	//printf("counter (nb of created threads) = %d\n", counter);
	return (0);
}

/*DESCRIPTION exec_philo
*	Philosophers (threads) are created
*		Returns(1) if error when creating threads.
*		
*/
int exec_philo(int argc, char **argv)
{
	t_args rules;

    get_rules(argc, argv, &rules);
	printf("number of philosophers = %d\n", rules.number_of_philosophers); //great!! rules are correctly updated
	pthread_mutex_init(&ledger_lock, NULL);
	if (create_philo_threads(rules) == 1)
	{
		putmessage3();
		return(1); //error found when creating threads
	}
	return (0); //everything went correctly
}