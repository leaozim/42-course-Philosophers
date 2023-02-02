/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:33:06 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/02 11:42:07 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include <bits/types/cookie_io_functions_t.h>

static void init_date(t_philo *data, t_common *common,  int i)
{
	data->is_dead = -1;
	data->id = i + 1;
	data->time_last_meal = 0;
	data->meals = common->must_eat;
	data->meals_eaten = 0;
	data->common = common;
	data->lock_meals = (t_mutex *)malloc(sizeof(t_mutex));
	pthread_mutex_init(data->lock_meals, NULL);
	data->look_meals_eaten = (t_mutex *)malloc(sizeof(t_mutex));
	pthread_mutex_init(data->look_meals_eaten, NULL);
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

static void shared_data( t_common *common, char **arguments)
{
	t_mutex *print;
	t_mutex *death;

	common->start = 0;
	common->number_of_philos = ft_atoi(arguments[1]);
	common->time_to_die = ft_atoi(arguments[2]);
	common->time_to_eat = ft_atoi(arguments[3]);
	common->time_to_sleep = ft_atoi(arguments[4]);
	if (arguments[5])
		common->must_eat = ft_atoi(arguments[5]);
	else
		common->must_eat = -1;
	print = (t_mutex *)malloc(sizeof(t_mutex));
	common->print = print;
	death = (t_mutex *)malloc(sizeof(t_mutex));
	common->death = death;
	pthread_mutex_init(common->print, NULL);
	pthread_mutex_init(common->death, NULL);
}

t_philo	*create_philos(int n_philos, char **arguments, t_common *common, t_mutex **fork)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * n_philos);
	*fork = init_forks(n_philos, fork);
	shared_data(common, arguments);
	printf("%d\n", common->number_of_philos);
	i = -1;
	while (++i < n_philos)
	{
		init_date(&philos[i], common,  i);
		assign_fork(&philos[i], fork, n_philos, i);
	}
	return (philos);
}
