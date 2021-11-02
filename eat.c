#include "philosophers.h"

void	eat(t_philos *philo, pthread_mutex_t *forks)
{
	printf("%d philosopher started to eat\n", philo->philo);
	pthread_mutex_lock(&forks[philo->left_fork]);
	pthread_mutex_lock(&forks[philo->right_fork]);

	printf("%d philosopher eats\n", philo->philo);

	pthread_mutex_unlock(&forks[philo->left_fork]);
	pthread_mutex_unlock(&forks[philo->right_fork]);
}