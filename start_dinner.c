#include "philosophers.h"

void	start_dinner(pthread_mutex_t *forks, t_main *args, t_philos **philos)
{
	int	i;

	i = 0;
	init_mutex(forks, args->n_of_philos);
	while (i < args->n_of_philos)
	{
		eat(philos[i], forks);
		i++;
	}
}