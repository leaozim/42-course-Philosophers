#include "../includes/philosophers.h"

void get_input(t_philo *data, pthread_mutex_t *mtx, char **arguments, int i)
{
	data->number_of_philos = ft_atoi(arguments[1]);
	data->id = i + 1;
	data->start = -1;
	data->time_to_die = ft_atoi(arguments[2]);
	data->time_to_eat = ft_atoi(arguments[3]);
	data->time_to_sleep = ft_atoi(arguments[4]);
	if (arguments[5])
		data->must_eat = ft_atoi(arguments[5]);
	else
		data->must_eat = -1;
	data->mutex = mtx;
}
