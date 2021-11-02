#include "philosophers.h"

void	eat(void *arg)
{
	t_arguments *arguments = (t_arguments *) arg;
	struct timeval new;
	suseconds_t time;

	// pthread_mutex_lock(&forks[philo->left_fork]);
	// gettimeofday(&new, NULL);
	// time = new.tv_usec;
	// printf("%d %d has taken a fork\n", (time - args->start), philo->philo);
	// pthread_mutex_lock(&forks[philo->right_fork]);
	// gettimeofday(&new, NULL);
	// time = new.tv_usec;
	// printf("%d %d has taken a fork\n", (time - args->start), philo->philo);
	// gettimeofday(&new, NULL);
	// time = new.tv_usec;
	// printf("%d %d is eating\n", (time - args->start), philo->philo);
	// pthread_mutex_unlock(&forks[philo->left_fork]);
	// pthread_mutex_unlock(&forks[philo->right_fork]);
}

void	think(t_philos *philo)
{
	printf("%d is thinking\n", philo->philo);
}