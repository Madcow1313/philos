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

void	make_args(t_main	*args, t_philos **philos, t_forks *forks, t_arguments *arguments)
{
	int	i;

	i = 0;
	while (i < args->n_of_philos)
	{
		philos[i]->last_meal = args->start;
		arguments[i].philos = philos[i];
		arguments[i].forks = forks;
		arguments[i].args = args;
		//printf("in %d\n", arguments[i + 1].philos[i + 1]->philo);
		i++;
	}
}

void	run_threads(pthread_t *thread, t_arguments *arguments)
{
	int	i;

	i = 0;
	// while (1)
	// {
		i = 0;
		while (i < arguments->args->n_of_philos)
		{
			if (i % 2 == 0)
			{	
				//arguments[i].args->start = get_time();
				pthread_create(&thread[i], NULL, eat, &arguments[i]);
				//pthread_join(thread[i], NULL);
				pthread_detach(thread[i]);
				//usleep(100);
			}
			i++;
		}
		i = 0;
		while (i < arguments->args->n_of_philos)
		{
			if (i % 2 != 0)
			{	
				//arguments[i].args->start = get_time();
				pthread_create(&thread[i], NULL, think, &arguments[i]);
				//pthread_join(thread[i], NULL);
				pthread_detach(thread[i]);
				//usleep(100);
			}
			i++;
		}
		i = 0;
		while (i < arguments->args->n_of_philos)
		{
			if (i % 2 != 0)
			{	
				//arguments[i].args->start = get_time();
				pthread_create(&thread[i], NULL, eat, &arguments[i]);
				//pthread_join(thread[i], NULL);
				pthread_detach(thread[i]);
				//usleep(100);
			}
			i++;
		}
	//}
}

void	start_supper(t_main	*args, t_philos **philos, t_forks *forks)
{
	t_arguments *arguments;
	pthread_t thread;

	args->start = get_time();
	arguments = malloc(sizeof(t_arguments) * args->n_of_philos);
	int i = 0;
	while (i < args->n_of_philos)
	{
		arguments[i].philos = malloc(sizeof(t_philos) * args->n_of_philos);
		arguments[i].philos = philos[i];
		//printf("philo is %d\n", arguments[i].philos->philo);
		arguments[i].args = malloc(sizeof(t_main));
		arguments[i].args = args;
		arguments[i].forks = malloc(sizeof(t_forks) * args->n_of_philos);
		arguments[i].forks = forks;
		arguments[i].forks->forks = malloc(sizeof(pthread_mutex_t) * args->n_of_philos);
		//printf("%lu\n", sizeof(arguments[i].forks->forks));
		arguments[i].forks->forks = forks->forks;
		i++;
	}
	//make_args(args, philos, forks, arguments);
	run_threads(&thread, arguments);
	// i = 0;
	// while (i < args->n_of_philos)
	// {
	// 	printf("out %d\n", arguments[i].philos->philo);
	// 	i++;
	// }
}
