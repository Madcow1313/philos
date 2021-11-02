#include "philosophers.h"

void	start_dinner(t_forks *forks, t_main *args, t_philos **philos)
{
	int	i;

	i = 0;
	init_mutex(forks, args->n_of_philos);
	while (i < args->n_of_philos - 1)
	{
		eat(philos[i], forks);
		i++;
	}
}