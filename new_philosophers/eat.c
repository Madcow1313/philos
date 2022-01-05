/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:46:07 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/05 12:11:34 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philos *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_to_write);
	printf("%ld %d has taken a fork\n",
		get_time() - philo->table->start_time, philo->philo_pos);
	pthread_mutex_unlock(philo->right_to_write);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->right_to_write);
	printf("%ld %d has taken a fork\n",
		get_time() - philo->table->start_time, philo->philo_pos);
	pthread_mutex_unlock(philo->right_to_write);
}

void	eat(t_philos *philo)
{
	pthread_mutex_lock(philo->right_to_write);
	printf("%ld %d is eating\n",
		get_time() - philo->table->start_time, philo->philo_pos);
	pthread_mutex_unlock(philo->right_to_write);
	usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->eaten_meals++;
}

void	philo_sleep(t_philos *philo)
{
	pthread_mutex_lock(philo->right_to_write);
	printf("%ld %d is sleeping\n",
		get_time() - philo->table->start_time, philo->philo_pos);
	pthread_mutex_unlock(philo->right_to_write);
	usleep(philo->table->time_to_sleep * 1000);
}

void	think(t_philos *philo)
{
	pthread_mutex_lock(philo->right_to_write);
	printf("%ld %d is thinking\n",
		get_time() - philo->table->start_time, philo->philo_pos);
	pthread_mutex_unlock(philo->right_to_write);
}

void	*routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	if ((philo->philo_pos - 1) % 2 != 0)
		think(philo);
	while (1)
	{
		take_forks(philo);
		philo->last_meal = get_time();
		eat(philo);
		if (philo->eaten_meals == philo->table->nb_of_meals
			&& philo->table->nb_of_meals > 0)
		{
			philo->done_eating = 1;
			philo->table->full_philo++;
		}
		philo_sleep(philo);
		think(philo);
	}
	return (0);
}
