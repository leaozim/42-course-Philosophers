/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:33:06 by lade-lim          #+#    #+#             */
/*   Updated: 2023/01/30 18:28:03 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void get_input(t_philo *data, pthread_mutex_t *mtx, char **arguments, int i)
{
	data->number_of_philos = ft_atoi(arguments[1]);
	data->id = i + 1;
	data->start = -1;
	data->time_to_die = ft_atoi(arguments[2]);
	data->time_to_eat = ft_atoi(arguments[3]);
	data->time_to_sleep = ft_atoi(arguments[4]);
	data->time_last_meal = -1;
	data->is_dead = FALSE;
	if (arguments[5])
		data->must_eat = ft_atoi(arguments[5]);
	else
		data->must_eat = -1;
	data->print = mtx;
	pthread_mutex_init(&data->death, NULL);
}



t_philo	*create_philos(int n_philos, char **arguments, pthread_mutex_t *print, pthread_mutex_t **fork)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * n_philos);
	*fork = malloc(sizeof(pthread_mutex_t) * n_philos);
	i = 0;
	while (i< n_philos)
	{
		pthread_mutex_init(&((*fork)[i]), NULL);
		i++;
	}
	i = 0;
	while (i < n_philos)
	{
		get_input(&philos[i], print, arguments, i);
		philos[i].left_fork = &((*fork)[i]);
		philos[i].right_fork = &((*fork)[(i + 1) % n_philos]);
		i++;
	}
	return (philos);
}