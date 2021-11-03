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
	//printf("%d has taken a fork\n", (time));
	pthread_mutex_unlock(arguments->forks->forks);
	return (0);
}

void	think(t_philos *philo)
{
	printf("%d is thinking\n", philo->philo);
}