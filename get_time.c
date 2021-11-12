#include "philosophers.h"

unsigned int	get_time()
{
	unsigned int			current_time;
	struct timeval	time;

	gettimeofday(&time, NULL);
	current_time = time.tv_sec / 1000 + time.tv_usec * 1000;
	return (current_time);
}