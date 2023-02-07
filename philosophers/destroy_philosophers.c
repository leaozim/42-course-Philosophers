/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_philosophers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:11:52 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/07 10:44:27 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	free_philos(t_philo *philos, t_mutex **fork)
{
	int	i;

	i = -1;
	while (++i < philos->common->n_philos)
	{
		pthread_mutex_destroy(philos[i].lock_meals);
		pthread_mutex_destroy(philos[i].look_meals_eaten);
		pthread_mutex_destroy(philos[i].look_stop);
		pthread_mutex_destroy(philos[i].look_current_time);
		pthread_mutex_destroy(philos[i].look_start);
		free(philos[i].lock_meals);
		free(philos[i].look_meals_eaten);
		free(philos[i].look_stop);
		free(philos[i].look_current_time);
		free(philos[i].look_start);
		pthread_mutex_destroy(&(*fork)[i]);
	}
	free(*fork);
}

static void	free_common(t_common *common)
{
	pthread_mutex_destroy(common->death);
	pthread_mutex_destroy(common->print);
	pthread_mutex_destroy(common->look_is_dead);
	pthread_mutex_destroy(common->look_everyone_ate);
	free(common->look_everyone_ate);
	free(common->look_is_dead);
	free(common->death);
	free(common->print);
}

void	destroy_philosophers(t_philo *philos, t_thread *dinner, t_mutex **fork)
{
	free_philos(philos, fork);
	free_common(philos->common);
	free(dinner);
	free(philos);
}
