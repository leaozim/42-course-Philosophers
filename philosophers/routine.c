/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:38:19 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/06 12:14:02 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	set_lastsupper(t_philo *philo)
{
	pthread_mutex_lock(philo->look_current_time);
	philo->time_start = get_timestamp(philo->common->start);
	pthread_mutex_unlock(philo->look_current_time);
}

void	print_actions(t_philo *philo, char *action)
{
	size_t current_time;

	if (lock_stop(philo) != 1)
	{
		pthread_mutex_lock(philo->common->print);
		current_time =  get_timestamp(philo->common->start);
		printf("%-5lu %d %s", current_time, philo->id, action);
		pthread_mutex_unlock(philo->common->print);

	}
}

void	*rotine(void *_philo)
{
	t_philo			*philo;

	philo = (t_philo *)_philo;
	if (philo->id % 2)
		ft_usleep(5);
	while (!philo->common->is_dead)
	{
		if (philo->common->is_dead || lock_stop(philo) == 1 || is_satiated(philo))
			return (NULL) ;
		eating(philo);
		if (philo->common->is_dead || lock_stop(philo)  == 1 || is_satiated(philo))
			return (NULL) ;
		sleeping(philo);
		if (philo->common->is_dead || lock_stop(philo)  == 1 || is_satiated(philo))
			return (NULL) ;
		thinking(philo);
		if (philo->common->is_dead || lock_stop(philo)  == 1 || is_satiated(philo))
			return (NULL) ;
	}
	return (NULL);
}