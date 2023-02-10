/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_variables2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:21:10 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/09 18:39:52 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	get_start(t_philo	*philo)
{
	int	start;

	pthread_mutex_lock(&philo->look_start);
	start = philo->time_start;
	pthread_mutex_unlock(&philo->look_start);
	return (start);
}

int	get_stop(t_philo	*philo)
{
	int	stop;

	pthread_mutex_lock(&philo->look_stop);
	stop = philo->stop;
	pthread_mutex_unlock(&philo->look_stop);
	return (stop);
}

size_t	get_last_meal(t_philo	*philo)
{
	size_t	last_meal;

	pthread_mutex_lock(&philo->lock_meals);
	last_meal = philo->time_last_meal;
	pthread_mutex_unlock(&philo->lock_meals);
	return (last_meal);
}

int	get_meals_eaten(t_philo	*philo)
{
	int	meals_eaten;

	pthread_mutex_lock(&philo->look_meals_eaten);
	meals_eaten = philo->meals_eaten;
	pthread_mutex_unlock(&philo->look_meals_eaten);
	return (meals_eaten);
}
