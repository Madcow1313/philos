#include "philosophers.h"

// void	start_dinner(pthread_mutex_t **forks, t_main *args, t_philos **philos)
// {
// 	t_arguments *arguments;
// 	pthread_t thread[args->n_of_philos];
// 	int	i;

// 	i = 0;
// 	arguments = malloc(sizeof(t_arguments));
// 	arguments->forks = forks;
// 	arguments->philos = philos;
// 	init_mutex(forks, args->n_of_philos);
// 				write(1, "?\n", 2);
// 	gettimeofday(&args->start_time, NULL);
// 	args->start = args->start_time.tv_usec;
// 	printf("%lu\n", sizeof(pthread_mutex_t));
// 	while (i < args->n_of_philos)
// 	{
// 		pthread_create(&thread[i], NULL, eat, &arguments[i]);
// 		i++;
// 	}
// }

void	start_supper(t_main	*args, t_philos **philos, t_forks *forks)
{
	t_arguments arguments[args->n_of_philos];
	pthread_t thread[args->n_of_philos];
	int	i;

	i = 0;
	//init_mutex(forks->forks, args->n_of_philos);
	while (i < args->n_of_philos)
	{
		arguments[i].philos = &philos[i];
		arguments[i].forks = forks;
		arguments[i].args = args;
		i++;
	}
	i = 0;
	gettimeofday(&args->start_time, NULL);
	args->start = args->start_time.tv_usec;
	while (i < args->n_of_philos)
	{
		pthread_create(&thread[i], NULL, eat, &arguments[i]);
		i++;
	}
}