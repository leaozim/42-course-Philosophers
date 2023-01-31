/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:33:20 by lade-lim          #+#    #+#             */
/*   Updated: 2023/01/31 11:24:05 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include <stddef.h>

void	*eye_of_horus(void *_philo)
{
	t_philo		*philos;
	int			i;

	philos = *(t_philo **)_philo;
	i = 0;
	while (1)
	{
		if (philos[i].must_eat == 0)
		{
			break ;
		}
	
		if	(get_timestamp(philos[i].start) - philos[i].time_last_meal > philos[i].time_of_death)
		{
			pthread_mutex_lock(&philos[i].death);
			pthread_mutex_lock(philos[i].print);
			philos->time_of_death = get_timestamp(philos[i].start);
			printf("%-5lu %d o gato morreu \n", get_timestamp(philos[i].start), philos[i].id);
			philos->is_dead = philos[i].id;
			pthread_mutex_unlock(philos[i].print);
			pthread_mutex_unlock(&philos[i].death);
			break ;
		}
		i++;
		if (i == philos[0].number_of_philos)
			i = 0;
	}
	return (NULL);
	
}

void	run_threads(pthread_t *dinner, pthread_t *death, t_philo *philos, int n_philos)
{
	int		i;
	size_t	start;

	i = -1;
	pthread_mutex_init(philos->print, NULL);
	start = get_time();
	while (++i < n_philos)
	{
		philos[i].start = start;
		philos[i].time_last_meal = start;
		pthread_create(&dinner[i], NULL, &rotine, &philos[i]);
	}
	pthread_create(death, NULL, &eye_of_horus, &philos);
	i = -1;
	while (++i < n_philos)
		pthread_join(dinner[i], NULL);
	pthread_join(*death, NULL);
	pthread_mutex_destroy(philos->print);
	pthread_mutex_destroy(&philos->death);
}
