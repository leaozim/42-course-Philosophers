/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_protections2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:21:10 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/07 10:24:04 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	lock_start(t_philo	*philo)
{
	int	start;

	pthread_mutex_lock(philo->look_start);
	start = philo->time_start;
	pthread_mutex_unlock(philo->look_start);
	return (start);
}

int	lock_stop(t_philo	*philo)
{
	int	stop;

	pthread_mutex_lock(philo->look_stop);
	stop = philo->stop;
	pthread_mutex_unlock(philo->look_stop);
	return (stop);
}
