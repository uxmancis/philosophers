/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:35:43 by uxmancis          #+#    #+#             */
/*   Updated: 2024/03/24 11:48:36 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_table table;
    
    if (argc == 5 || argc == 6)
    {
        //correct number of inputs
        parse_input(&table, argv); //1. errors checking, filling table
        data_init(&table); //2. create the thing
        dinner_start(&table); //3
        clean(&table); //No leaks, 4. either when philos are full or 2. 1 philo dies
    }
    else
    {
        error_exit("Wrong input:\n"
                G"Correct is ./philo 5 800 200 200 [5]" RST);
    }
}