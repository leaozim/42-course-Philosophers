/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stopping_conditions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:13:12 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/07 10:44:56 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	is_satiated(t_philo *philo)
{
	int	i;

	i = 0;
	if (lock_meals_eaten(philo) == philo->common->must_eat)
	{
		pthread_mutex_lock(philo->common->look_everyone_ate);
		philo->common->everyone_ate += 1;
		pthread_mutex_unlock(philo->common->look_everyone_ate);
		if (lock_everyone_ate(philo) == philo->common->n_philos)
		{
			while (i < philo->common->n_philos)
			{
				pthread_mutex_lock(philo->look_stop);
				philo->stop = 1;
				i++;
				pthread_mutex_unlock(philo->look_stop);
			}	
		}
		return (TRUE);
	}
	return (FALSE);
}

void	set_is_dead(t_philo *philos)
{
	int	i;

	i = 0;
	pthread_mutex_lock(philos->common->look_is_dead);
	philos->common->is_dead = 1;
	pthread_mutex_unlock(philos->common->look_is_dead);
	while (i < (*philos).common->n_philos)
	{
		philos[i].stop_while = 1;
		pthread_mutex_lock(philos->look_stop);
		philos[i].stop = 1;
		i++;
		pthread_mutex_unlock(philos->look_stop);
	}
}
