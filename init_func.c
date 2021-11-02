#include "philosophers.h"

void	init_philos(t_philos *philo, int ordinal_number, int left_fork, int right_fork)
{
	philo->philo = ordinal_number;
	philo->left_fork = left_fork;
	philo->right_fork = right_fork;
}

void	init_mutex(pthread_mutex_t *forks, int n_of_philos)
{
	int	i;

	i = 0;
	while (i < n_of_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}
