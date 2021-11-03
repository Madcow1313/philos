#include "philosophers.h"


int main(int argc, char **argv)
{
	t_forks	*forks;
	t_main	*args;
	t_philos *philos;

	philos = NULL;
	forks = NULL;
	if (argc > 6 || argc < 5)
	{
		write(2, "Error! Wrong number of arguments!\n", 34);
		return (0);
	}
	args = malloc(sizeof(t_main));
	if (!args)
	{
		write (2, "Error! Something went wrong with malloc!\n", 42);
		if (args)
			free (args);
		return (0);
	}
	if (fill_main_struct(args, argc, argv) == - 1)
	{
		write (2, "Error! Wrong arguments!\n", 25);
		return (0);
	}
	forks = malloc(sizeof(t_forks) * (args->n_of_philos));
	philos = malloc(sizeof(t_philos) * (args->n_of_philos));
	pthread_mutex_t real_forks[args->n_of_philos];
	//printf("%d\n", args->n_of_philos);
	forks->forks = real_forks;
	
	if (start_gathering(args, &philos) == -1)
	{
		write (2, "Error! Something went wrong with malloc!\n", 42);
		if (args)
			free (args);
		if (forks)
			free (forks);
		return (0);
	}
	//start_dinner(forks, args, &philos);
	start_supper(args, &philos, forks);
	while (1);
	return (0);
}