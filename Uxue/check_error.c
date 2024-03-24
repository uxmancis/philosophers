/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:28:15 by uxmancis          #+#    #+#             */
/*   Updated: 2024/03/23 18:44:49 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*check_digits returns:
*	1: YES error found (not only digits [0-9] along arguments)
*	0: NO error found, (only digitss [0-9] were found along argument)
---------------------------------------------------*/
int	check_digits(int argc, char **argv)
{
	int	x;
	int	y;
	int	times;

	x = 1;
	y = 0;
	times = argc - 1;
	while (times > 0)
	{
		y = 0;
		while (argv[x][y] != '\0')
		{
			if (ft_isdigit(argv[x][y]) != 1)
				return (1);
			y++;
		}
		x++;
		times --;
	}
	return (0);
}

/*check_error contains total errors wanna check in our philo
*	program.
*
*	Any other potential errors we would like to check can be 
*	called from this check_error function.
*
*	In any case, check_error will return 1 when any of the errors
*	happens.
*
*	Returns:
*		0: NO ERROR was found
*		1: Some error was found
*
*	List of error we check:
*		1) check_digits: make sure only [0-9] digits are allowed.
*/
int	check_error(int argc, char **argv)
{
	if (check_digits(argc, argv) == 0)
		return (1);
	return (0);
}
