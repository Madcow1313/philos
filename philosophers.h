#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>

typedef struct s_philos
{
	int philo;
	int left_fork;
	int right_fork;
	int	life;
	int	last_meal;
	int	eating_counter;
	pthread_mutex_t	mutex;
}			t_philos;

typedef struct s_main_struct
{
	int n_of_philos;
	int time_to_eat;
	int time_to_die;
	int	time_to_sleep;
	int	number_of_times_each_ph_must_eat;
	struct timeval start_time;
	suseconds_t	start;
}	t_main;

typedef struct s_forks
{
	pthread_mutex_t *forks;
}				t_forks;

typedef struct s_arguments
{
	t_philos	**philos;
	t_forks	*forks;
	t_main *args;
}				t_arguments;


int	fill_main_struct(t_main *list, int argc, char **argv);
signed long long	ft_atoi_long(const char	*string);
void	init_philos(t_philos *philo, int ordinal_number, int left_fork, int right_fork);
void	init_mutex(pthread_mutex_t *forks, int n_of_philos);
int	start_gathering(t_main *args, t_philos **philos);
void	start_dinner(pthread_mutex_t **forks, t_main *args, t_philos **philos);
void	*eat(void *arg);
void	start_supper(t_main	*args, t_philos **philos, t_forks *forks);
void	*philo_sleep(void *arg);
#endif