/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_protections1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:17:34 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/07 10:31:56 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	lock_everyone_ate(t_philo	*philo)
{
	int	everyone_ate;

	pthread_mutex_lock(philo->common->look_everyone_ate);
	everyone_ate = philo->common->everyone_ate;
	pthread_mutex_unlock(philo->common->look_everyone_ate);
	return (everyone_ate);
}

int	lock_is_dead(t_philo	*philo)
{
	int	is_dead;

	pthread_mutex_lock(philo->common->look_is_dead);
	is_dead = philo->common->is_dead;
	pthread_mutex_unlock(philo->common->look_is_dead);
	return (is_dead);
}

size_t	lock_time(t_philo	*philo)
{
	size_t	last_meal;

	pthread_mutex_lock(philo->lock_meals);
	last_meal = philo->time_last_meal;
	pthread_mutex_unlock(philo->lock_meals);
	return (last_meal);
}

int	lock_meals_eaten(t_philo	*philo)
{
	int	meals_eaten;

	pthread_mutex_lock(philo->look_meals_eaten);
	meals_eaten = philo->meals_eaten;
	pthread_mutex_unlock(philo->look_meals_eaten);
	return (meals_eaten);
}
