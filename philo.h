/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:33:58 by uxmancis          #+#    #+#             */
/*   Updated: 2024/03/16 16:31:41 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h> //write
# include <stdio.h>
# include <signal.h> //kill, SIGUSR1, SIGUSR2
# include <pthread.h>

typedef struct s_args
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}		t_args;

//philosophers.c
int ft_isdigit(char c);
int check_digits(int argc, char **argv);

//error_messages.c
void putmessage(void);
void putmessage2(void);
void putmessage3(void);

//exec.c
int exec_philo(int argc, char **argv);
int create_philo_threads(t_args rules);
void *ft_actions(void *data);
void set_rules (int argc, char **argv, t_args *rules);
int get_rule_1 (char **argv);
int get_rule_2 (char **argv);
int get_rule_3 (char **argv);
int get_rule_4 (char **argv);
int get_rule_5 (char **argv);

//utils.c
int ft_atoi(char **argv);
int get_int(char c, int index, int len_arg);
int get_multiplier(int index, int len_arg);
int ft_strlen(char *str);
int ft_isdigit(char c);

#endif