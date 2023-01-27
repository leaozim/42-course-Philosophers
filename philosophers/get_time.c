#include "../includes/philosophers.h"

size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

size_t	get_timestamp(size_t start)
{
	return(get_time() - start);
}
