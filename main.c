#include "philosophers.h"

int main(int argc, char **argv)
{
	t_forks	*forks;
	t_main	*args;
	t_philos **philos;

	args = malloc(sizeof(t_main));
	if (check_args_and_fill(args, argc, argv) == -1)
		return (0);
	forks = malloc(sizeof(*(forks)));
	philos = malloc(sizeof(t_philos) * (args->n_of_philos));
	forks->forks = malloc(sizeof(*(forks->forks)) * (args->n_of_philos));
	int i = 0;
	while (i < args->n_of_philos)
	{
		philos[i] = malloc(sizeof(*(philos[i])));
		i++;
	}
	if (check_mallocs_and_gather(forks, philos, args) == -1)
		return (0);
	if (init_mutex(forks->forks, args->n_of_philos) == 1)
	{
		return (0);
	}
	init_philo_mutex(philos, args->n_of_philos);
	philos = give_forks(args, philos);
	//printf("%d\n", args->n_of_philos);
	start_supper(args, philos, forks);
	pthread_exit(NULL);
	free_and_exit(forks, philos, args, args->n_of_philos);
	return (0);
}
