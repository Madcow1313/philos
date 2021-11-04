#include "philosophers.h"

void	*eat(void *arg)
{
	t_arguments *arguments = (t_arguments *) arg;
	struct timeval new;
	suseconds_t time;
	t_philos *philosopher;
	t_forks	*forks;

	pthread_mutex_t entry = PTHREAD_MUTEX_INITIALIZER;

	philosopher = *arguments->philos;
	forks = arguments->forks;
	pthread_mutex_lock(&entry);
	pthread_mutex_lock(&forks->forks[philosopher->left_fork]);
	gettimeofday(&new, NULL);
	time = new.tv_usec;
	printf("%d %d has taken a %d fork\n", (time - arguments->args->start), philosopher->philo, philosopher->left_fork);
	pthread_mutex_lock(&forks->forks[philosopher->right_fork]);
	gettimeofday(&new, NULL);
	time = new.tv_usec;
	printf("%d %d has taken a %d fork\n", (time - arguments->args->start), philosopher->philo, philosopher->right_fork);
	//sleep(1);
	printf("%d finished\n", philosopher->philo);
	pthread_mutex_unlock(&forks->forks[philosopher->right_fork]);
	pthread_mutex_unlock(&forks->forks[philosopher->left_fork]);
	pthread_mutex_unlock(&entry);
	return (0);
}

void	think(t_philos *philo)
{
	printf("%d is thinking\n", philo->philo);
}