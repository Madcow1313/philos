#include "philosophers.h"

void	ft_putnbr_fd(long n, int fd)
{
	char	temp_char;

	if (n == -2147483648 || n == -2147483648LL)
		write(fd, "-2147483648", 11);
	if (n == 0)
		write(fd, "0", 1);
	else if (n != -2147483648 || n != -2147483648LL)
	{
		if (n < 0)
		{
			n = -n;
			write(fd, "-", 1);
		}
		if (n < 10 && n > 0)
		{
			temp_char = n + 48;
			write(fd, &temp_char, 1);
		}
		else
		{
			ft_putnbr_fd(n / 10, fd);
			temp_char = n % 10 + 48;
			write(fd, &temp_char, 1);
		}
	}
}

void	print_sleep(t_philos *philo)
{
	ft_putnbr_fd((get_time() - philo->table->start_time)/10, 1);
	ft_putnbr_fd(philo->philo_pos, 1);
	write(1, " is sleeping\n", 13);
}
void	print_eat(t_philos *philo)
{
	ft_putnbr_fd((get_time() - philo->table->start_time)/10, 1);
	ft_putnbr_fd(philo->philo_pos, 1);
	write(1, " is eating\n", 11);
}

void	print_fork(t_philos *philo)
{
	ft_putnbr_fd((get_time() - philo->table->start_time)/10, 1);
	ft_putnbr_fd(philo->philo_pos, 1);
	write(1, " has taken a fork\n", 18);	
}

void	print_think(t_philos *philo)
{
	ft_putnbr_fd((get_time() - philo->table->start_time)/10, 1);
	ft_putnbr_fd(philo->philo_pos, 1);
	write(1, " is thinking\n", 14);	
}