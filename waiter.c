#include "philosophers.h"

static void	*service(void *args)
{
	t_arguments *arguments;
	t_philos	*philosophers;
	int	i;
	int j;

	arguments = (t_arguments *)args;
	j = arguments->args->n_of_philos;
	i = 0;
	philosophers = *arguments->philos;
	while (1)
	{
		pthread_mutex_lock(&philosophers->mutex);
		if (get_time() - philosophers->last_meal > (unsigned int)arguments->args->time_to_die)
		{	
			//pthread_exit(NULL);
			break;
		}
		pthread_mutex_unlock(&philosophers->mutex);
		usleep(100);
		//write(1, "wth\n", 4);
	}
	printf("Philosopher %d is dead at %d\n", i + 1, get_time() - philosophers->last_meal);
	return (0);
}

void call_waiter(t_arguments *arguments)
{
	pthread_t waiter_thread;

	pthread_create(&waiter_thread, NULL, service, arguments);
	pthread_detach(waiter_thread);
}