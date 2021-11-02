#include "philosophers.h"

void	eat(t_philos *philo, pthread_mutex_t *forks)
{
	printf("%d philosopher started to eat\n", philo->philo);
	pthread_mutex_lock(&forks[philo->left_fork]);
	pthread_mutex_lock(&forks[philo->right_fork]);
	usleep(100000);
	printf("%d philosopher eats\n", philo->philo);
	pthread_mutex_unlock(&forks[philo->left_fork]);
	pthread_mutex_unlock(&forks[philo->right_fork]);
}

void	think(t_philos *philo)
{
	printf("%d is thinking\n", philo->philo);
}