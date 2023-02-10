/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:38:19 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/07 18:55:24 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	one_philo(t_philo *philo)
{
	if (philo->common->n_philos == 1)
	{
		print_actions(philo, TAKE_FORK);
		return (EXIT_FAILURE);
	}
	return (0);
}

int	more_than_one_philo(t_philo *philo)
{
	int		is_dead;
	int		stop;

	if (philo->id % 2)
		ft_usleep(5);
	is_dead = get_is_dead(philo);
	while (!is_dead)
	{
		stop = get_stop(philo);
		if (is_dead || stop || is_satiated(philo))
			return (EXIT_FAILURE);
		eating(philo);
		if (is_dead || stop || is_satiated(philo))
			return (EXIT_FAILURE);
		sleeping(philo);
		if (is_dead || stop || is_satiated(philo))
			return (EXIT_FAILURE);
		thinking(philo);
		if (is_dead || stop || is_satiated(philo))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	*rotine(void *_philo)
{
	t_philo	*philo;

	philo = (t_philo *)_philo;
	if (one_philo(philo))
		return (NULL);
	else if (more_than_one_philo(philo))
		return (NULL);
	return (NULL);
}
