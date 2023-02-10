/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:49:36 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/09 16:52:56 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_death(t_philo *philo, char *action)
{
	size_t	current_time;

	pthread_mutex_lock(&philo->common->print);
	current_time = get_timestamp(philo->common->start);
	printf("%-5lu %d %s", current_time, philo->id, action);
	pthread_mutex_unlock(&philo->common->print);
}

void	print_actions(t_philo *philo, char *action)
{
	size_t	current_time;

	pthread_mutex_lock(&philo->common->print);
	if (get_stop(philo) != 1)
	{
		current_time = get_timestamp(philo->common->start);
		printf("%-5lu %d %s", current_time, philo->id, action);
	}
	pthread_mutex_unlock(&philo->common->print);
}
