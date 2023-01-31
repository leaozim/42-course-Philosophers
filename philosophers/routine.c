/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:38:19 by lade-lim          #+#    #+#             */
/*   Updated: 2023/01/31 11:08:52 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include <stdio.h>

void	print_actions(t_philo *philo, char *action)
{
	pthread_mutex_lock(philo->print);
	printf("%-5lu %d %s", get_timestamp(philo->start), philo->id, action);
	pthread_mutex_unlock(philo->print);
}

void	pick_up_the_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	print_actions(philo, TAKE_FORK);
	print_actions(philo, TAKE_FORK);
	// printf("%-5lu %d  has taken a fork \n", get_timestamp(philo->start), philo->id);	
	// pthread_mutex_unlock(philo->print);
}

void	drop_the_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	eating(t_philo *philo)
{
	pick_up_the_fork(philo);
	pthread_mutex_lock(philo->print);
	printf("%-5lu %d is eating\n", get_timestamp(philo->start), philo->id);
	philo->must_eat--;
	// printf("must eat = %d\n", philo->must_eat);
	philo->time_last_meal = get_time();
	pthread_mutex_unlock(philo->print);
	// print_actions(philo, EATING);
	drop_the_fork(philo);
	usleep(philo->time_to_eat * 1000);
	return (0);
}

int	sleeping(t_philo *philo)
{
	print_actions(philo, SLEEPING);
	usleep(philo->time_to_sleep * 1000);
	return (0);
}

int	thinking(t_philo *philo)
{
	print_actions(philo, THINKING);
	return (0);
}

void	*rotine(void *_philo)
{
	t_philo			*philo;

	philo = (t_philo *)_philo;
	while (philo->must_eat)
		
	{
		eating(philo);
		if (philo->is_dead)
			break ;
		if (philo->must_eat == 0)
			break ;
		sleeping(philo);
		thinking(philo);
		printf("-------------------------iuiudfsdfbn--------------------------\n");
			
			// break ;
	}
	// while (eating(philo) && sleeping(philo) && thinking(philo))
	// {
	// 	printf("sssoi\n");
	// 	continue ;
	// }
	return (NULL);
}