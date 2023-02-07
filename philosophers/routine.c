/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:38:19 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/07 09:45:22 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_actions(t_philo *philo, char *action)
{
	size_t current_time;

	pthread_mutex_lock(philo->common->print);
	if (lock_stop(philo) != 1)
	{
		current_time =  get_timestamp(philo->common->start);
		printf("%-5lu %d %s", current_time, philo->id, action);
	}
	pthread_mutex_unlock(philo->common->print);
}

void	*rotine(void *_philo)
{
	t_philo	*philo;
	int		is_dead;
	int		stop;
	// int		is_satiated;

	philo = (t_philo *)_philo;
	if (philo->id % 2)
		ft_usleep(5);
	is_dead = lock_is_dead(philo);
	while (!is_dead)
	{
		stop = lock_stop(philo);
		
		if (is_dead || stop || is_satiated(philo))
			return (NULL) ;
		eating(philo);
		if (is_dead || stop || is_satiated(philo))
			return (NULL) ;
		sleeping(philo);
		if (is_dead || stop || is_satiated(philo))
			return (NULL) ;
		thinking(philo);
		if (is_dead || stop || is_satiated(philo))
			return (NULL) ;
	}
	return (NULL);
}