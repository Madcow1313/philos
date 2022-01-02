#include "philosophers.h"

void	free_all(t_main *list)
{
	int	i;

	i = 0;
	while (i < list->nb_of_philos)
	{
		if (list->forks)
			pthread_mutex_destroy(&(list->forks[i]));
		i++;
	}
	if (list->forks)
		free(list->forks);
	if (list->philos)
		free(list->philos);
	pthread_mutex_destroy(list->right_to_write);
}

int	start_dinner(t_main *list)
{
	list->right_to_write = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(list->right_to_write, NULL))
	{
		write (1, "Error: cant't init mutex!\n", 26);
		return (0);
	}
	gather_philos(list);
	return (1);
}

int	init_all(t_main *list, int argc, char **argv)
{
	if (!fill_main_struct(list, argc, argv))
	{
		write (1, "Error: Wrong arguments!\n", 24);
		return (0);
	}
	if (!(init_philos(list)))
	{
		write (1, "Error: something went wrong with malloc!\n", 41);
		return (0);
	}
	if (!init_mutex(list))
	{
		write (1, "Error: cant't init mutex!\n", 26);
		return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_main list;

	if (!check_input(argc, argv))
	{
		write (1, "Error: Wrong arguments!\n", 24);
		return (0);
	}
	if (!init_all(&list, argc, argv))
		return (0);
	start_dinner(&list);
	run_threads(&list);
	free_all(&list);
	return (0);
}