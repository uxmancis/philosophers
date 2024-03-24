/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:32:01 by uxmancis          #+#    #+#             */
/*   Updated: 2024/03/23 11:50:45 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Pdte.
*	- MAX INT
*/

void	putmessage(void)
{
	write(1, "Hi there! If you wanted to see what this philosophers' ", 55);
	write(1, "project is capable of doing, try entering ", 42);
	write(1, "the following arguments:\n", 26);
	write(1, "· number_of_philosophers\n", 26);
	write(1, "· time_to_die\n", 15);
	write(1, "· time_to_eat\n", 15);
	write(1, "· time_to_sleep\n", 17);
	write(1, "· number_of_times_each_philosopher_must_eat (optional)\n", 56);
	write(1, "\n", 1);
	write(1, "Here you have an example:\n", 27);
	write(1, "./philo 6778 8888 2222 1111 5555\n", 34);
}

void	putmessage2(void)
{
	write(1, "Make sure only [0-9] digits are allowed along arguments\n", 57);
	write(1, "Here you have an example:\n", 27);
	write(1, "./philo 6778 8888 2222 1111 5555\n", 34);
}

void	putmessage3(void)
{
	write(1, "Error when creating thread\n", 26);
}
