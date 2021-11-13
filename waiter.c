#include "philosophers.h"

static void	*service(void *args)
{
	t_arguments *arguments;
	t_philos	**philosophers;
	int	i;
	int j;

	arguments = (t_arguments *)args;
	j = arguments[0].args->n_of_philos;
	i = 0;
	philosophers = arguments->philos;
	call_waiter(arguments);
	while (1)
	{
		pthread_mutex_lock(&philosophers[i]->mutex);
		if (get_time() - philosophers[i]->last_meal > (unsigned int)arguments[i].args->time_to_die)
		{	
			printf("Philosopher %d is dead at %d\n", i + 1, get_time() - philosophers[i]->last_meal);
			break;
		}
		pthread_mutex_unlock(&philosophers[i]->mutex);
		i++;
		if (i <= j)
		{
			i = 0;
			usleep(1);
		}
	}
	return (0);
}

void call_waiter(t_arguments *arguments)
{
	pthread_t waiter_thread;

	pthread_create(&waiter_thread, NULL, service, arguments);
	pthread_detach(waiter_thread);
}