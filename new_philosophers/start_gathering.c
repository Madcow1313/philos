#include "philosophers.h"

void	give_forks(t_main *list)
{
	int	i;

	i = 0;
	while (i < list->nb_of_philos)
	{
		if (i == 0)
		{
			list->philos[i].left_fork = &list->forks[list->nb_of_philos - 1];
			list->philos[i].right_fork = &list->forks[i];
		}
		else if (i == list->nb_of_philos - 1)
		{
			list->philos[i].left_fork = &list->forks[i - 1];
			list->philos[i].right_fork = &list->forks[list->nb_of_philos - 1];
		}
		else
		{
			list->philos[i].left_fork = &list->forks[i - 1];
			list->philos[i].right_fork = &list->forks[i];
		}
		list->philos[i].eaten_meals = 0;
		i++;
	}
}

void	gather_philos(t_main *list)
{
	int	i;

	i = 0;
	give_forks(list);
	while (i < list->nb_of_philos)
	{
		list->philos[i].right_to_write = list->right_to_write;
		list->philos[i].table = list;
		i++;
	}
}