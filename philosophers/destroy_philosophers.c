/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_philosophers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:11:52 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/06 17:38:59 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	destroy_philosophers(t_philo *philos, t_thread *dinner, t_mutex **fork)
{
	int	i;

	i = -1;
	while (++i < philos->common->number_of_philos)
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
	pthread_mutex_destroy(philos->common->death);
	pthread_mutex_destroy(philos->common->print);
	// pthread_mutex_destroy(philos->common->look_is_dead);
	// free(philos->common->look_is_dead);
	free(philos->common->death);
	free(philos->common->print);
	free(*fork);
	free(dinner);
	free(philos);
}
