#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>

typedef struct s_philos t_philos;

typedef struct s_main
{
	int nb_of_philos;
	int nb_of_meals;
	pthread_mutex_t *forks;
	pthread_mutex_t	*right_to_write;
	t_philos    *philos;
	long    start_time;
	long    time_to_eat;
	long    time_to_die;
	long    time_to_sleep;
}	t_main;

typedef struct s_philos
{
	int philo_pos;
	int eaten_meals;
	long last_meal;
	long start_time;
	int	done_eating;
	pthread_mutex_t *right_to_write;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	t_main *table;
}	t_philos;

signed long long	ft_atoi_long(const char	*string);
int check_input(int argc, char **argv);
int	fill_main_struct(t_main *list, int argc, char **argv);
int	init_philos(t_main *list);
int	init_mutex(t_main *list);
void	run_threads(t_main *list);
void	gather_philos(t_main *list);
void	*routine(void *arg);
long	get_time();
#endif