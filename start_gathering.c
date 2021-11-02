#include "philosophers.h"

void give_forks(t_main *args, t_philos **philos)
{
	int	i = 0;
	while (i < args->n_of_philos)
	{
		philos[i] = malloc(sizeof(t_philos));
		write (1, "!\n", 2);
		if (i == 0)
		{
			philos[i]->philo = i + 1;
			philos[i]->left_fork = args->n_of_philos;
			philos[i]->right_fork = i;
		}
		else if (i == args->n_of_philos - 1)
		{
			philos[i]->philo = i + 1;
			philos[i]->left_fork = args->n_of_philos - 1;
			philos[i]->right_fork = args->n_of_philos;
		}
		else
		{
			philos[i]->philo = i + 1;
			philos[i]->left_fork = i - 1;
			philos[i]->right_fork = i;
		}
		i++;
	}
}


int	start_gathering(t_main *args, t_philos **philos)
{
	if (!philos)
		return (-1);
	give_forks(args, philos);
	return (0);
}