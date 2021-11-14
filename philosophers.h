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
	unsigned int	last_meal;
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
	unsigned int	start;
}	t_main;

typedef struct s_forks
{
	pthread_mutex_t *forks;
}				t_forks;

typedef struct s_arguments
{
	t_philos	*philos;
	t_forks	*forks;
	t_main *args;
}				t_arguments;


int	fill_main_struct(t_main *list, int argc, char **argv);
signed long long	ft_atoi_long(const char	*string);
int	check_args_and_fill(t_main *args, int argc, char **argv);
int	check_mallocs_and_gather(t_forks *forks, t_philos **philos, t_main *args);
void	init_philos(t_philos *philo, int ordinal_number, int left_fork, int right_fork);
int	init_mutex(pthread_mutex_t *forks, int n_of_philos);
t_philos **give_forks(t_main *args, t_philos **philos);
void	start_dinner(pthread_mutex_t **forks, t_main *args, t_philos **philos);
void	*eat(void *arg);
void	start_supper(t_main	*args, t_philos **philos, t_forks *forks);
void	*philo_sleep(void *arg);
int	free_and_exit(t_forks *forks, t_philos **philos, t_main *args, int i);
int	start_gathering(t_main *args, t_philos **philos);
unsigned int	get_time();
void	*think(void *arg);
void call_waiter(t_arguments *arguments);
void	init_philo_mutex(t_philos **philos, int n_of_philos);
#endif