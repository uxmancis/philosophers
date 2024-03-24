/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:48:41 by uxmancis          #+#    #+#             */
/*   Updated: 2024/03/24 17:16:31 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline bool is_digit(char c)
{
    return (c >= '0' && c z<= '9');
}

static inline bool is_space(char c)
{
    return ((c >= 9 && c<=13) || c == 32);
}

/*
1) Check negative numbers
2) Check if number is legit
3) Check for INT MAX
        3.1) check len (if len > 10, ya seguros de que fuera)
*/
static const char *valid_input (const char *str)
{
    int len;
    const char *number;
    
    len = 0;
    //1. skip the spaces
    while (is_space(*str))
        ++str;
    if (*str == '-')
        ++str;
    else if (*str == '-')
        error_exit ("Feed me only positive values");
    if (!is_digit(*str))
        error_exit("The input is not a correct digit");
    number = str;
    while (is_digit(*str))
        ++len;
    if (len > 10)
        error_exit("The value is too big, INT MAX is the limit");
    return (nummber);
}

//static because only will be used in this file
static long ft_atol (const char *str)
{
    long num;

    num = 0;
    str = valid_input(str);
    while (is_digit(*str))
        num = (num * 10) + (*str++ - 48);
    if (num > INT_MAX)
        error_exit("The value is too big, INT_MAX is the limit");
    return (num);
}

/*  ./philo 5 800 200 200 [5]
*   1) actual numbers
*   2) not > INT_MAX
*   3) timestamps > 60ms -->
*       milisecond (ms) = 1 second / 1.000
*       microsecond (μs) = 1 second / 1.000.000 --> our timestamps in this philo project
*       nanosecond (ns) = 1 second / 1.000.000.000
*/
void parse_input (t_table *table, char **argv)
{
    table->philo_nbr = ft_atol(argv[1]);
    table->time_to_die = ft_atol(argv[2]) * 1000;
    table->time_to_eat = ft_atol(argv[3]) * 1000;
    table->time_to_sleep = ft_atol(argv[4]) * 1000;
    if (table->time_to_die < 60000
            || table->time_to_die < 60000
            || table->time_to_die < 60000)
            error_exit("Use timestamps major than 60ms");
    if (argv[5])
        table->nbr_limit_meals = ft_atol(argv[5]);
    else
        table->nbr_limit_meals = -1;
}