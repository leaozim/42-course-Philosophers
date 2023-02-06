/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:33:20 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/06 12:17:54 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include <unistd.h>

size_t	lock_time(t_philo	*philo)
{
	size_t	last_meal;

	pthread_mutex_lock(philo->lock_meals);
	last_meal = philo->time_last_meal;
	pthread_mutex_unlock(philo->lock_meals);
	return (last_meal);
}

int	lock_stop(t_philo	*philo)
{
	int	stop;

	pthread_mutex_lock(philo->look_stop);
	stop = philo->stop;
	pthread_mutex_unlock(philo->look_stop);
	return (stop);
}

int	lock_meals_eaten(t_philo	*philo)
{
	int	meals_eaten;

	pthread_mutex_lock(philo->look_meals_eaten);
	meals_eaten = philo->meals_eaten;
	pthread_mutex_unlock(philo->look_meals_eaten);
	return (meals_eaten);
}

int	lock_start(t_philo	*philo)
{
	int	start;

	pthread_mutex_lock(philo->look_start);
	start = philo->time_start;
	pthread_mutex_unlock(philo->look_start);
	return (start);
}

int	is_satiated(t_philo *philo)
{
	int i;

	i = 0;
	if (lock_meals_eaten(philo) == philo->common->must_eat)
	{
		philo->common->everyone_ate += 1;
		if (philo->common->everyone_ate == philo->common->number_of_philos)
		{
			while (i < philo->common->number_of_philos)
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

void set_is_dead(t_philo *philos)
{
	int i;
	i = 0;
	philos->common->is_dead = 1;
	while (i < (*philos).common->number_of_philos)
	{
		pthread_mutex_lock(philos->look_stop);
		philos[i].stop = 1;
		i++;
		pthread_mutex_unlock(philos->look_stop);
	}
}

void	*eye_of_horus(void *_philo)
{
	t_philo		*philos;
	size_t		current_time;
	int			i;

	philos = (t_philo *)_philo;
	i = 0;
	usleep(100);
	while (lock_stop(&philos[i]) == 0)
	{
		current_time = get_timestamp(philos->common->start);
		if (current_time - lock_time(&philos[i]) > philos->common->time_to_die)
		{
			pthread_mutex_lock(philos->common->death);
			set_is_dead(philos);
			pthread_mutex_unlock(philos->common->death);
			pthread_mutex_lock(philos->common->print);
			printf(RED"%-5lu %d  the cat is die\n"RESET, get_timestamp(philos->common->start), philos[i].id);
			pthread_mutex_unlock(philos->common->print);
			return (NULL) ; 
		}
		if (philos->common->everyone_ate == philos->common->number_of_philos || lock_stop(&philos[i]) == 1)
			return (NULL) ;
		i++;
		if (i == philos->common->number_of_philos)
			i = 0;
		ft_usleep(1);
	}
	return (NULL);
	
}

void	run_threads(pthread_t *dinner, pthread_t *death, t_philo *philos, int n_philos)
{
	int		i;

	i = -1;
	philos->common->start = get_time();
	while (++i < n_philos)
		pthread_create(&dinner[i], NULL, &rotine, (void *)&philos[i]);
	i = -1;
	pthread_create(death, NULL, &eye_of_horus, (void *)philos);
	while (++i < n_philos)
		pthread_join(dinner[i], NULL);
	pthread_join(*death, NULL);

	
}
