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
	//pthread_mutex_unlock(arguments->forks->forks);
	return (0);
}

void	think(t_philos *philo)
{
	printf("%d is thinking\n", philo->philo);
}