#include "philosophers.h"

void	eat();

int	check_death(t_main *list, int i)
{
	if (get_time() - list->philos[i].last_meal > list->time_to_die)
	{
		pthread_mutex_lock(&list->right_to_write);
		printf("%ld %d philosopher is dead\n",
			get_time(), i + 1);
		return (0);
	}
	return (1);
}

void	waiter(t_main *list)
{
	int	i;
	int	philo_full;

	i = 0;
	philo_full = 0;
	while (1)
	{
		i = 0;
		while (i < list->nb_of_philos)
		{
			if (list->philos[i].eaten_meals >= list->nb_of_meals
				&& !list->philos[i].done_eating
				&& list->nb_of_meals > 0)
				philo_full++;
			if (!check_death(list, i))
				return ;
			i++;
		}
		if (philo_full >= list->nb_of_philos)
		{
			pthread_mutex_lock(&list->right_to_write);
			return ;
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
			if (pthread_create(&thread, NULL, eat, &list->philos[i]))
			{
				pthread_mutex_lock(&list->right_to_write);
				printf("Error, unable to create thread\n");
				return ;
			}
			pthread_detach(thread);
		}
		i++;
	}
	i = 0;
	while (i < list->nb_of_philos)
	{
		if (i % 2 != 0)
		{	
			if (pthread_create(&thread, NULL, eat, &list->philos[i]))
			{
				pthread_mutex_lock(&list->right_to_write);
				printf("Error, unable to create thread\n");
				return ;
			}
		}
		i++;
	}
	waiter(list);
}