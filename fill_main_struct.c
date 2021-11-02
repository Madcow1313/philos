#include "philosophers.h"

int	fill_main_struct(t_main *list, int argc, char **argv)
{
	list->n_of_philos = ft_atoi_long(argv[1]);
	list->time_to_die = ft_atoi_long(argv[2]);
	list->time_to_eat = ft_atoi_long(argv[3]);
	list->time_to_sleep = ft_atoi_long(argv[4]);
	if (list->n_of_philos < 0 || list->time_to_die < 0
		|| list->time_to_eat < 0 || list->time_to_sleep < 0)
	{
		return (-1);
	}
	if (argc == 6)
	{
		list->number_of_times_each_ph_must_eat = ft_atoi_long(argv[5]);
		if (list->number_of_times_each_ph_must_eat < 0)
			return (-1);
	}
	return (0);
}