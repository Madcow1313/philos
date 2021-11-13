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
		arguments[i].philos = &philos[i];
		arguments[i].forks = forks;
		arguments[i].args = args;
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
	make_args(args, philos, forks, arguments);
	call_waiter(arguments);
	run_threads(&thread, arguments);
}
