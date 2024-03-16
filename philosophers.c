/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:35:21 by uxmancis          #+#    #+#             */
/*   Updated: 2024/03/16 16:05:06 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*check_digits returns:
*	1: YES only digits [0-9] along arguments
*	0: NOt just digits, other characters found
---------------------------------------------------*/
int check_digits(int argc, char **argv)
{
	int x;
	int y;
	int times;

	x = 1;
	y = 0;
	times = argc - 1;
	while (times > 0)
	{
		y = 0;
		while (argv[x][y] != '\0')
		{
			if (ft_isdigit(argv[x][y]) != 1)
				return (0);
			y++;
		}
		x++;
		times --;
	}
	return (1);
}

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
