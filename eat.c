#include "philosophers.h"

int g = 0;

void	*eat(void *arg)
{
	t_arguments *arguments = (t_arguments *) arg;
	unsigned int time;
	t_philos *philosopher;
	t_forks	*forks;

	philosopher = arguments->philos;
	forks = arguments->forks;
	while (1)
	{
		//call_waiter(arguments);
		//pthread_mutex_lock(&philosopher->mutex);
		//printf("%d\n",g++);
		//printf("error %d\n", pthread_mutex_lock(&forks->forks[philosopher->left_fork]));
		pthread_mutex_lock(&forks->forks[philosopher->left_fork]);
		time = get_time();
		printf("%u %d has taken a %d fork\n", (time - arguments->args->start), philosopher->philo, philosopher->left_fork);
		pthread_mutex_lock(&forks->forks[philosopher->right_fork]);
		time = get_time();
		printf("%u %d has taken a %d fork\n", (time - arguments->args->start), philosopher->philo, philosopher->right_fork);
		printf("%u %d is eating\n", (time - arguments->args->start), philosopher->philo);
		usleep(arguments->args->time_to_eat * 1000);
		philosopher->last_meal = get_time();
		pthread_mutex_unlock(&forks->forks[philosopher->left_fork]);
		pthread_mutex_unlock(&forks->forks[philosopher->right_fork]);
		// philosopher->eating_counter--;
		// if (philosopher->eating_counter < -100)
		// 	philosopher->eating_counter = -1;
		philo_sleep(arg);
		pthread_mutex_unlock(&philosopher->mutex);
		// if (philosopher->eating_counter == 0)
		// {
		// 	printf("%d philosopher is full\n", philosopher->philo);
		// 	break;
		// }
	}
	return (0);
}

void	*think(void *arg)
{
	t_arguments	*arguments = (t_arguments *) arg;
	t_philos *philosopher;
	unsigned int time;

	philosopher = arguments->philos;
	time = get_time();
	//pthread_mutex_lock(&philosopher->mutex);
	printf("%u %d is thinking\n", (time - arguments->args->start), philosopher->philo);
	usleep((arguments->args->time_to_die - 60) * 1000);
	//pthread_mutex_unlock(&philosopher->mutex);
	return (0);
}

void	*philo_sleep(void *arg)
{
	t_arguments	*arguments = (t_arguments *) arg;
	t_philos *philosopher;
	unsigned int	time;

	philosopher = arguments->philos;
	time = get_time();
	//pthread_mutex_lock(&philosopher->mutex);
	printf("%u %d is sleeping\n", (time - arguments->args->start), philosopher->philo);
	usleep(arguments->args->time_to_sleep * 1000);
	//pthread_mutex_unlock(&philosopher->mutex);
	return (0);
}
