#include "philosophers.h"

void	take_forks(t_philos *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_to_write);
	printf("%ld %d philosopher has taken a fork\n", get_time() - philo->table->start_time, philo->philo_pos);
	pthread_mutex_unlock(philo->right_to_write);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->right_to_write);
	printf("%ld %d philosopher has taken a fork\n", get_time() - philo->table->start_time, philo->philo_pos);
	pthread_mutex_unlock(philo->right_to_write);
}

void	eat(t_philos *philo)
{
	pthread_mutex_lock(philo->right_to_write);
	printf("%ld %d philosopher is eating\n", get_time() - philo->table->start_time, philo->philo_pos);
	pthread_mutex_unlock(philo->right_to_write);
	usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_sleep(t_philos *philo)
{
	pthread_mutex_lock(philo->right_to_write);
	printf("%ld %d philosopher is sleeping\n", get_time() - philo->table->start_time, philo->philo_pos);
	pthread_mutex_unlock(philo->right_to_write);
	usleep(philo->table->time_to_sleep * 1000);
}

void	think(t_philos *philo)
{
	pthread_mutex_lock(philo->right_to_write);
	printf("%ld %d philosopher is thinking\n", get_time() - philo->table->start_time, philo->philo_pos);
	pthread_mutex_unlock(philo->right_to_write);
	usleep(philo->table->time_to_sleep * 1000);	
}

void	*routine(void *arg)
{
	t_philos *philo;

	philo = (t_philos *)arg;
	while(1)
	{
		take_forks(philo);
		philo->last_meal = get_time();
		eat(philo);
		philo_sleep(philo);
		think(philo);
	}		
}
