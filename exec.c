/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:52:00 by uxmancis          #+#    #+#             */
/*   Updated: 2024/03/16 17:28:18 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int get_rule_1 (char **argv)
{
	int result;

	result = ft_atoi(argv);
	//printf("exec.c get_rule_1 | result = %d\n", result);
	return (result);
}
 
int get_rule_2 (char **argv)
{
	(void)argv;
	return (0);
}

int get_rule_3 (char **argv)
{
	(void)argv;
	return (0);
}
int get_rule_4 (char **argv)
{
	(void)argv;
	return (0);
}

int get_rule_5 (char **argv)
{
	(void)argv;
	return (0);
}

/*DESCRIPTION set_rules:
*	set_rules function gets the rules defined when executing ./philo program
*
*	The rules must be indicated only using [0-9] digits as we are talking
*	about time.
*
*	4 or 5 rules will need to be defined to execute ./philo program, as 
*	5th rule is optional to the user.
*---------------------------------------------------------------------------*/
void set_rules (int argc, char **argv, t_args *rules)
{
	(void)argc;
	rules->number_of_philosophers = get_rule_1(argv);
	//printf("set_rules | number_of_philosophers = %d\n", rules->number_of_philosophers);
    rules->time_to_die = get_rule_2(argv);
    rules->time_to_die = get_rule_3(argv);
	rules->time_to_sleep = get_rule_4(argv);
	rules->number_of_times_each_philosopher_must_eat = get_rule_5(argv);
}

void *ft_actions(void *data)
{
	(void)data;
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
		if (pthread_create(&philosopher[i], NULL, ft_actions, NULL) != 0)
			return(1);
		rules.number_of_philosophers--;
		i++;  
		//counter++;
	}
	/*i = keep_number_of_philosophers;
	while (i > 0)
	{
		printf("ID Philosopher (thread) = %d\n", philosopher[i]); //%lu = unsigned long int
		i++;
	}*/
	i = 0;
	while (keep_number_of_philosophers > 0)
	{
		pthread_join(philosopher[i], NULL);
		keep_number_of_philosophers--;
		i++;
	}
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
	
    set_rules(argc, argv, &rules);
	printf("number of philosophers = %d\n", rules.number_of_philosophers); //great!! rules are correctly updated
	if (create_philo_threads(rules) == 1)
	{
		putmessage3();
		return(1); //error found when creating threads
	}
	return (0); //everything when correctly
}