/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:33:06 by lade-lim          #+#    #+#             */
/*   Updated: 2023/01/30 21:10:19 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void init_date(t_philo *data, t_mutex *mtx, char **arguments, int i)
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

static void	assign_fork(t_philo *philos, t_mutex **fork, int n_philos, int i)
{
	philos->left_fork = &((*fork)[i]);
	philos->right_fork = &((*fork)[(i + 1) % n_philos]);
}

static t_mutex	*init_forks(int n_philos, t_mutex **fork)
{
	int		i;

	i = -1;
	*fork = malloc(sizeof(t_mutex) * n_philos);
	while (++i < n_philos)
		pthread_mutex_init(&((*fork)[i]), NULL);
	return (*fork);
}

t_philo	*create_philos(int n_philos, char **arguments, t_mutex *print, t_mutex **fork)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * n_philos);
	*fork = init_forks(n_philos, fork);
	i = -1;
	while (++i < n_philos)
	{
		init_date(&philos[i], print, arguments, i);
		assign_fork(&philos[i], fork, n_philos, i);
	}
	return (philos);
}
