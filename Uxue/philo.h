/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:33:58 by uxmancis          #+#    #+#             */
/*   Updated: 2024/03/23 19:00:42 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h> //write
# include <stdio.h> //printf
# include <signal.h> //kill, SIGUSR1, SIGUSR2
# include <stdlib.h> //malloc, free
# include <sys/time.h> //gettimeofday
# include <pthread.h> // mutex (init,destroy,lock,unlock)
					//threads (create, join, detach)

/*t_args stores arguments received from terminal specified
*	by user when executing our philo program.
*--------------------------------------------------------*/
typedef struct s_args
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_times_philos_must_eat_not_2_die;
}		t_args;

struct s_fork;
{
	t_mtx fork,
};

typedef struct s_philo
{
	unsigned long int	philo_id;
	void				*left_fork;
	void				*right_fork;
	int					nb_meals;
	bool				full;
	long				last_meal_time;
	pthread_t			thread_id;
}		t_philo;

//philosophers.c
int ft_isdigit(char c);


//check_error.c
int	check_error(int argc, char **argv);

//put_error.c
void putmessage(void);
void putmessage2(void);
void putmessage3(void);

//exec.c
int exec_philo(int argc, char **argv);
int create_philo_threads(t_args rules);
void *ft_actions(void *data);
void get_rules (int argc, char **argv, t_args *rules);
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
int check_digits(int argc, char **argv);

#endif