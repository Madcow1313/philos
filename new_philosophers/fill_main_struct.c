/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_main_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:47:27 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/05 11:47:36 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	fill_main_struct(t_main *list, int argc, char **argv)
{
	list->nb_of_philos = (int)ft_atoi_long(argv[1]);
	list->time_to_die = (int)ft_atoi_long(argv[2]);
	list->time_to_eat = (int)ft_atoi_long(argv[3]);
	list->time_to_sleep = (int)ft_atoi_long(argv[4]);
	if (list->nb_of_philos <= 0 || list->time_to_die <= 0
		|| list->time_to_eat <= 0 || list->time_to_sleep <= 0)
	{
		return (0);
	}
	if (argc == 6)
	{
		list->nb_of_meals = (int)ft_atoi_long(argv[5]);
		if (list->nb_of_meals <= 0)
			return (0);
	}
	else
		list->nb_of_meals = -1;
	return (1);
}
