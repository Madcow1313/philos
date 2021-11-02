#include "philosophers.h"

void	start_dinner(pthread_mutex_t *forks, t_main *args, t_philos **philos)
{
	t_arguments *arguments;
	pthread_t thread[args->n_of_philos];
	int	i;

	i = 0;
	arguments = malloc(sizeof(t_arguments));
	arguments->forks = forks;
	arguments->philos = philos;
	init_mutex(forks, args->n_of_philos);
	gettimeofday(&args->start_time, NULL);
	args->start = args->start_time.tv_usec;
	while (i < args->n_of_philos)
	{
		pthread_create(&thread[i], NULL, eat, &arguments[i]);
		i++;
	}
}