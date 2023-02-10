/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:17:34 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/09 18:39:49 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	get_everyone_ate(t_philo	*philo)
{
	int	everyone_ate;

	pthread_mutex_lock(&philo->common->look_everyone_ate);
	everyone_ate = philo->common->everyone_ate;
	pthread_mutex_unlock(&philo->common->look_everyone_ate);
	return (everyone_ate);
}

int	get_is_dead(t_philo	*philo)
{
	int	is_dead;

	pthread_mutex_lock(&philo->common->look_is_dead);
	is_dead = philo->common->is_dead;
	pthread_mutex_unlock(&philo->common->look_is_dead);
	return (is_dead);
}
