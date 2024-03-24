/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:22:15 by uxmancis          #+#    #+#             */
/*   Updated: 2024/03/24 17:14:22 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf
#include <stdlib.h> //malloc, free
#include <unistd.h> //write, usleep
#include <stdbool.h>
#include <pthread.h> //mutex: init, destroy, lock, unlock
                    //threads: create join detach
#include <sys/time.h> //gettimeofday (cronómetro)
#include <limits.h>

//Syncronization problem, where X threads (philosophers)
// try to access to same resources (fork)

//How Oceano has modelled the problem: 2 arrays (philos & forks-mutex)

typedef pthread_mutex_t t_mtx; //more readable code
typedef struct s_table	t_table; //for compiler

/*
**	ANSI Escape Sequences for Bold Text Colors
**	Usage:
**		printf(R "This is red text." RST);
**		printf(B "This is blue text." RST);
**	Remember to use RST to reset colour after settint it.
*/
# define RST	"\033[0m"		/*	Reset to default colour */
# define RED	"\033[1;31m"	/*	Bold Red */
# define G		"\033[1;32m"	/*	Bold Green */
# define W		"\033[1;37m"	/*	Bold White */

#define DEBUG_MODE 0 //write function macro

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;

/*PHILO states*/
typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}		t_philo_status;

/**/
enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}	t_time_code;

/*fork*/
typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}		t_fork;

/*
*/
typedef struct s_philo
{
	int	id;
	long	meals_counter;
	bool	full;
	long	last_meal_time; //time passed from last meal --> has philosopher died or not? microseconds
	t_fork	*first_fork; //before called left_fork, but now changed because of odd/even philos implementation
	t_fork	*second_fork; //before called left_fork, but now changed because of odd/even philos implementation
	pthread_t	thread_id; //philosopher's ID
	t_mtx 	philo_mutex; //useful for races with the monitor
}				t_philo;

typedef struct s_table
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_limit_meals; //if -1 = no value assigned
	long	start_simulation; //when does simulation start?
	bool	end_simulation; //turned on if 1. philo dies or 2. all philos full
	bool	all_threads_ready;
	t_mtx	table_mutex; //avoid races while reading from table
	t_mtx	write_mutex;
	t_fork	*forks;
	t_philo	*philos;
}				t_table;

//dinner.c
void write_status(t_philo_status status, t_philo *philo, bool debug);

//init.c
void data_init (t_table *table);

//parsing.c
void parse_input (t_table *table, char **argv);

//safe_functions.c
void *safe_malloc(size_t bytes);
static void handle_mutex_error(int status, t_opcode opcode);
void safe_mutex_handle(t_mtx *mutex, t_opcode opcode);
static void handle_thread_error(int status, t_opcode opcode);
void safe_thread_handle (pthread_t *thread, void *(*foo)(void *),
        void *data, t_opcode opcode);

//getters_setters.c
void set_bool(t_mtx *mutex, bool *dst, bool value);
bool get_bool (t_mtx *mutex, bool *value);
long get_long(t_mtx *mutex, long *value);
void set_long(t_mtx *mutex, long *dest, long value);
bool simulation_finished(t_table *table);

//synchro_utils.c
void wait_all_threads(t_table *table);

//utils.c
void precise_usleep(long usec, t_table *table);
void    error_exit (const char *error);