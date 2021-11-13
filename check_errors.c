#include "philosophers.h"

int	free_and_exit(t_forks *forks, t_philos **philos, t_main *args, int i)
{
	while (i >= 0)
		free(philos[i--]);
	free (forks->forks);
	free (forks);
	free (philos);
	free (args);
	write (2, "Error! Something went wrong with malloc!\n", 42);
	return (-1);
}

int	check_mallocs_and_gather(t_forks *forks, t_philos **philos, t_main *args)
{
	int i = 0;

	if (!forks || !philos || !forks->forks)
	{
		write (2, "Error! Something went wrong with malloc!\n", 42);
		if (args)
			free (args);
		if (forks->forks)
			free (forks);
		if (forks)
			free (forks);
		if (philos)
			free (philos);
		return (-1);
	}
	while (i < args->n_of_philos)
	{
		philos[i] = malloc(sizeof(t_philos));
		if (!philos[i])
			return(free_and_exit(forks, philos, args, i - 1));
		pthread_mutex_init(&philos[i]->mutex, NULL);
		i++;
	}
	return (0);
}


int	check_args_and_fill(t_main *args, int argc, char **argv)
{
	if (!args)
	{
		write (2, "Error! Something went wrong with malloc!\n", 42);
		return (-1);
	}
	if (argc > 6 || argc < 5)
	{
		free(args);
		write(2, "Error! Wrong number of arguments!\n", 34);
		return (-1);
	}
	if (fill_main_struct(args, argc, argv) == - 1)
	{
		free (args);
		write (2, "Error! Wrong arguments!\n", 25);
		return (-1);
	}
	return (0);
}