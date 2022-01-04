#include "philosophers.h"

int	check_death(t_main *list, int i)
{
	if (get_time() - list->philos[i].last_meal > list->time_to_die)
	{
		pthread_mutex_lock(list->right_to_write);
		printf("%ld %d died\n",
			get_time() - list->start_time, i + 1);
		return (0);
	}
	return (1);
}

void	waiter(t_main *list)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		//pthread_mutex_lock(list->right_to_write);
		if (list->full_philo == list->nb_of_philos)
		{
			pthread_mutex_lock(list->right_to_write);
			return ;
		}
		//pthread_mutex_unlock(list->right_to_write);
		while (i < list->nb_of_philos)
		{
			if (!check_death(list, i))
				return ;
			i++;
		}
		usleep(100);
	}
}

void	run_threads(t_main *list)
{
	int	i;
	pthread_t	thread;

	i = 0;
	list->start_time = get_time();
	while (i < list->nb_of_philos)
	{
		if (i % 2 == 0)
		{	
			list->philos[i].last_meal = list->start_time;
			if (pthread_create(&thread, NULL, routine, &list->philos[i]))
			{
				pthread_mutex_lock(list->right_to_write);
				printf("Error, unable to create thread\n");
				return ;
			}
			//usleep(100);
			pthread_detach(thread);
		}
		i++;
	}
	//usleep(1000);
	i = 0;
	while (i < list->nb_of_philos)
	{
		if (i % 2 != 0)
		{	
			list->philos[i].last_meal = list->start_time;
			if (pthread_create(&thread, NULL, routine, &list->philos[i]))
			{
				pthread_mutex_lock(list->right_to_write);
				printf("Error, unable to create thread\n");
				return ;
			}
			//usleep(100);
			pthread_detach(thread);
		}
		i++;
	}
	waiter(list);
}
