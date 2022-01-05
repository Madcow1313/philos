/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:49:06 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/05 12:17:57 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (list->full_philo == list->nb_of_philos)
		{
			pthread_mutex_lock(list->right_to_write);
			return ;
		}
		while (i < list->nb_of_philos)
		{
			if (!check_death(list, i))
				return ;
			i++;
		}
		usleep(1000);
	}
}

int	run_even(t_main *list, pthread_t *thread)
{
	int			i;

	i = 0;
	while (i < list->nb_of_philos)
	{
		if (i % 2 == 0)
		{	
			list->philos[i].last_meal = list->start_time;
			if (pthread_create(thread, NULL, routine, &list->philos[i]))
			{
				pthread_mutex_lock(list->right_to_write);
				printf("Error, unable to create thread\n");
				return (0);
			}
			pthread_detach(*thread);
		}
		i++;
	}
	return (1);
}

int	run_odd(t_main *list, pthread_t *thread)
{
	int	i;

	i = 0;
	while (i < list->nb_of_philos)
	{
		if (i % 2 != 0)
		{	
			list->philos[i].last_meal = list->start_time;
			if (pthread_create(thread, NULL, routine, &list->philos[i]))
			{
				pthread_mutex_lock(list->right_to_write);
				printf("Error, unable to create thread\n");
				return (0);
			}
			pthread_detach(*thread);
		}
		i++;
	}
	return (1);
}

void	run_threads(t_main *list)
{
	pthread_t	thread;

	list->start_time = get_time();
	if (!run_even(list, &thread))
		return ;
	if (!run_odd(list, &thread))
		return ;
	waiter(list);
}
