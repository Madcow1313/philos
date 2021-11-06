#include "philosophers.h"

void	*eat(void *arg)
{
	t_arguments *arguments = (t_arguments *) arg;
	struct timeval new;
	suseconds_t time;
	t_philos *philosopher;
	t_forks	*forks;

	philosopher = *arguments->philos;
	forks = arguments->forks;
	pthread_mutex_lock(&forks->forks[philosopher->left_fork]);
	gettimeofday(&new, NULL);
	time = new.tv_usec;
	printf("%d %d has taken a %d fork\n", (time - arguments->args->start), philosopher->philo, philosopher->left_fork);
	pthread_mutex_lock(&forks->forks[philosopher->right_fork]);
	gettimeofday(&new, NULL);
	time = new.tv_usec;
	printf("%d %d has taken a %d fork\n", (time - arguments->args->start), philosopher->philo, philosopher->right_fork);
	printf("%d %d is eating\n", (time - arguments->args->start), philosopher->philo);
	usleep(arguments->args->time_to_eat * 1000);
	philo_sleep(arg);
	pthread_mutex_unlock(&forks->forks[philosopher->left_fork]);
	pthread_mutex_unlock(&forks->forks[philosopher->right_fork]);
	return (0);
}

void	*think(void *arg)
{
	t_arguments	*arguments = (t_arguments *) arg;
	t_philos *philosopher;
	struct timeval new;
	suseconds_t time;

	philosopher = *arguments->philos;
	gettimeofday(&new, NULL);
	time = new.tv_usec;
	printf("%d %d is thinking\n", (time - arguments->args->start), philosopher->philo);
	return (0);
}

void	*philo_sleep(void *arg)
{
	t_arguments	*arguments = (t_arguments *) arg;
	t_philos *philosopher;
	struct timeval new;
	suseconds_t time;

	philosopher = *arguments->philos;
	gettimeofday(&new, NULL);
	time = new.tv_usec;
	printf("%d %d is sleeping\n", (time - arguments->args->start), philosopher->philo);
	usleep(arguments->args->time_to_sleep * 1000);
	return (0);
}