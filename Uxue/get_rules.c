/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:54:14 by uxmancis          #+#    #+#             */
/*   Updated: 2024/03/23 18:58:01 by uxmancis         ###   ########.fr       */
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
void get_rules (int argc, char **argv, t_args *rules)
{
	(void)argc;
	rules->number_of_philosophers = get_rule_1(argv);
	//printf("set_rules | number_of_philosophers = %d\n", rules->number_of_philosophers);
    rules->time_to_die = get_rule_2(argv);
    rules->time_to_die = get_rule_3(argv);
	rules->time_to_sleep = get_rule_4(argv);
    if (argv[5])
        rules->number_of_times_each_philosopher_must_eat = get_rule_5(argv);
    else
        rules->number_of_times_each_philosopher_must_eat = -1; //indicador de que no ha venido informada la variable opcional
}