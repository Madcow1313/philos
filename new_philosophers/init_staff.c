#include "philosophers.h"

int	init_mutex(t_main *list)
{
	int	i;

	i = 0;
	list->forks = malloc(sizeof(pthread_mutex_t) * list->nb_of_philos);
	if (!list->forks)
		return (0);
	while (i < list->nb_of_philos)
	{
		if (pthread_mutex_init(&(list->forks[i]), NULL))
			return (0);
		i++;
	}
	return (1);
}

int	init_philos(t_main *list)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	list->philos = malloc(sizeof(t_philos) * list->nb_of_philos);
	if (!(list->philos))
		return (0);
	while (i < list->nb_of_philos)
	{
		list->philos[j].philo_pos = i + 1;
		j++;
		i++;
	}
	return (1);
}