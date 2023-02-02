/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:33:20 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/02 11:44:22 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


size_t	lock_time(t_philo	*philo)
{
	size_t	last_meal;

	pthread_mutex_lock(philo->lock_meals);
	last_meal = philo->time_last_meal;
	pthread_mutex_unlock(philo->lock_meals);
	return (last_meal);
}


int	is_satiated(t_philo *philo)
{
	pthread_mutex_lock(philo->look_meals_eaten);
	if (philo->meals > 0 && philo->meals_eaten == philo->meals)
	{
		pthread_mutex_unlock(philo->look_meals_eaten);
		return (TRUE);
	}
	pthread_mutex_unlock(philo->look_meals_eaten);
	return (FALSE);
}

t_bool	is_dead(t_philo *philo)
{
	int	is_dead;

	pthread_mutex_lock (philo->common->death);
	is_dead = FALSE;
	if (philo->is_dead == -1)
	{
		is_dead = TRUE;
	}
	pthread_mutex_unlock(philo->common->death);
	return (is_dead);
}
void	*eye_of_horus(void *_philo)
{
	t_philo		*philos;
	size_t		current_time;
	int			i;

	philos = *(t_philo **)_philo;
	i = 0;
	while (1)
	{
		if (is_satiated(&philos[i]) || is_dead(philos))
			break ;
		current_time = get_timestamp(philos->common->start);
		if (current_time - philos[i].time_last_meal > philos->common->time_to_die)
		{
			pthread_mutex_lock(philos->common->death);
			philos->is_dead = 2;
			pthread_mutex_lock(philos->common->print);
			printf(RED"%-5lu %d  the cat is die\n"RESET, current_time, philos[i].id);
			pthread_mutex_unlock(philos->common->print);
			pthread_mutex_unlock(philos->common->death);
		}
		i++;
		if (i == philos->common->number_of_philos)
			i = 0;
		usleep(5);
	}
	return (NULL);
	
}

void	run_threads(pthread_t *dinner, pthread_t *death, t_philo *philos, int n_philos)
{
	int		i;
	// size_t	start;

	i = -1;
	// usleep(500);
	// pthread_mutex_init(philos->common->print, NULL);
	// philos[i + 1].time_last_meal = get_timestamp(start);
	// philos->common->must_eat = n_philos;
	
	philos->common->start = get_time();
	while (++i < n_philos)
	{
		// philos[i].time_last_meal = 0;
		pthread_create(&dinner[i], NULL, &rotine, &philos[i]);
	}
	i = -1;
	pthread_create(death, NULL, &eye_of_horus, &philos);
	while (++i < n_philos)
		pthread_join(dinner[i], NULL);
	// pthread_join(*death, NULL);
	pthread_mutex_destroy(philos->common->death);
	pthread_mutex_destroy(philos->common->print);
	pthread_mutex_destroy(philos->lock_meals);
	pthread_mutex_destroy(philos->look_meals_eaten);
}
