/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:33:20 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/02 09:50:26 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


size_t	lock_time(t_philo	*philo)
{
	size_t	last_meal;

	pthread_mutex_lock(philo->fome);
	last_meal = philo->time_last_meal;
	pthread_mutex_unlock(philo->fome);
	return (last_meal);
}

t_bool	its_full(t_philo *philos)
{
	pthread_mutex_lock(philos->quanto_tempo_de_fome);
	philos->meals--;
	printf("-------------------------------\n");
	if (!(philos->meals))
	{
		printf("-------------------------------\n");
		philos->common->must_eat--;
		pthread_mutex_unlock(philos->quanto_tempo_de_fome);
		return (TRUE);
	}
	pthread_mutex_unlock(philos->quanto_tempo_de_fome);
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
	int			i;

	philos = *(t_philo **)_philo;
	i = 0;
	// if (philos->id % 2 == 0)
	printf("-------------------------- %d\n",philos->common->must_eat );
	while (philos->common->must_eat)
	{
		// size_t now = get_time() - philos->common->start;
		// if	(now - lock_time(&philos[i]) > philos->common->time_to_die)
		// {
		// 	// printf("time_to_die    = %lu\n", philos->common->time_to_die);
		// 	// printf("time start     = %lu\n", philos->common->start);
		// 	// printf("time last meal = %lu\n", philos[i].time_last_meal);
		// 	// printf("get_timestamp  = %lu\n", now);
		// 	// // printf("current time   = %lu\n", philos->start - );
		// 	// printf("current time   = %lu\n", get_time());
		// 	// printf("result         = %lu\n", now - lock_time(&philos[i]));
		// 	// printf("----------------------------------\n");
			
		// 	pthread_mutex_lock(philos->common->print);
		// 	printf(RED"%-5lu %d  the cat is die\n"RESET, get_timestamp(philos[i].common->start), philos[i].id);
		// 	pthread_mutex_unlock(philos->common->print);
		// 	pthread_mutex_lock(philos->common->death);
		// 	philos->is_dead = philos[i].id;
		// 	pthread_mutex_unlock(philos->common->death);
		// 	break ;
		// }
		// pthread_mutex_unlock(&philos[i].death);
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
		philos->common->must_eat = n_philos;

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
	pthread_join(*death, NULL);
	pthread_mutex_destroy(philos->common->death);
	pthread_mutex_destroy(philos->common->print);
	pthread_mutex_destroy(philos->fome);
	pthread_mutex_destroy(philos->quanto_tempo_de_fome);
}
