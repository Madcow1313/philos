#include "philosophers.h"

void	init_philos(t_philos *philo, int ordinal_number, int left_fork, int right_fork)
{
	philo->philo = ordinal_number;
	philo->left_fork = left_fork;
	philo->right_fork = right_fork;
}

void	init_mutex(t_forks *forks, int n_of_philos)
{
	int	i;

	i = 0;
	while (i < n_of_philos)
	{
		write(1, "Iamhere\n", 8);
		pthread_mutex_init(&forks->forks[i], NULL);
		write(1, "shit\n", 5);
		i++;
	}
}
