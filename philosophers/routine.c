/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:38:19 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/02 11:42:43 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include <pthread.h>
#include <stddef.h>
#include <stdio.h>

void	print_actions(t_philo *philo, char *action)
{
	size_t current_time;

	current_time =  get_timestamp(philo->common->start);
	pthread_mutex_lock(philo->common->print);
	printf("%-5lu %d %s", current_time, philo->id, action);
	pthread_mutex_unlock(philo->common->print);
	if (ft_strcmp(action, EATING))
		philo->time_last_meal = current_time;
}

static void	pick_up_forks(t_philo *philo)
{
	size_t current_time;

	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->common->print);
	current_time =  get_timestamp(philo->common->start);
	printf("%-5lu %d %s", current_time, philo->id, TAKE_FORK);
	printf("%-5lu %d %s", current_time, philo->id, TAKE_FORK);
	pthread_mutex_unlock(philo->common->print);
}

static void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
int	eating(t_philo *philo)
{
		// if (is_dead(philo))
		// 	return (1);
	pick_up_forks(philo);
	print_actions(philo, EATING);
	usleep(philo->common->time_to_eat * 1000);
	drop_forks(philo);
	pthread_mutex_lock(philo->look_meals_eaten);
	philo->meals_eaten += 1;
	pthread_mutex_unlock(philo->look_meals_eaten);
	return (0);
}

int	sleeping(t_philo *philo)
{
	// if (is_dead(philo))
	// 	return (1);
	print_actions(philo, SLEEPING);
	usleep(philo->common->time_to_sleep * 1000);
	return (0);
}

int	thinking(t_philo *philo)
{
	// if (is_dead(philo))
	// 	return (1);
	print_actions(philo, THINKING);
	return (0);
}

void	*rotine(void *_philo)
{
	t_philo			*philo;

	philo = (t_philo *)_philo;
	if (philo->id % 2)
		usleep(20);
	while (1)
	{
		if (eating(philo))
			break ;
		if(is_satiated(philo))
			break ;
		if (sleeping(philo))
			break ;
		if (thinking(philo))
			break ;
		// usleep(500);
	}
	return (NULL);
}