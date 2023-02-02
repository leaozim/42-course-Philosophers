/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:38:19 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/02 09:49:58 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include <pthread.h>
#include <stdio.h>

void	print_actions(t_philo *philo, char *action)
{
	pthread_mutex_lock(philo->common->print);
	printf("%-5lu %d %s", get_timestamp(philo->common->start), philo->id, action);
	pthread_mutex_unlock(philo->common->print);
}

void	pick_up_the_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->common->print);
	printf("%-5lu %d %s", get_timestamp(philo->common->start), philo->id, TAKE_FORK);
	printf("%-5lu %d %s", get_timestamp(philo->common->start), philo->id, TAKE_FORK);
	printf("%-5lu %d is eating\n", get_timestamp(philo->common->start), philo->id);
	pthread_mutex_unlock(philo->common->print);
	pthread_mutex_lock(philo->fome);
	philo->time_last_meal = get_timestamp(philo->common->start);
	pthread_mutex_unlock(philo->fome);
	usleep(philo->common->time_to_eat * 1000);
	// philo->meals--;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	// pthread_mutex_lock(philo->quanto_tempo_de_fome);
	// pthread_mutex_unlock(philo->quanto_tempo_de_fome);
	// drop_the_fork(philo);
}

void	drop_the_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	eating(t_philo *philo)
{
	if (is_dead(philo))
	{
		return (1);
	}
	pick_up_the_fork(philo);
	
	// pthread_mutex_lock(philo->print);
	// if (is_dead(philo))
	// 	return (1);
	// printf("%-5lu %d is eating\n", get_timestamp(philo->start), philo->id);
	
	// pthread_mutex_lock(&philo->quanto_tempo_de_fome);
	// philo->time_last_meal = get_timestamp(philo->start);
	// pthread_mutex_unlock(&philo->quanto_tempo_de_fome);
	// if (philo->id == 1)
	// {
	// 	printf("----------------------------\n");
	// 	printf("rotine | time last = %lu\n", philo->time_last_meal);
	// 	printf("----------------------------\n");
	// }
	// pthread_mutex_unlock(philo->print);
	// pthread_mutex_lock(&philo->fome);
	// philo->must_eat--;
	// pthread_mutex_unlock(&philo->fome);
	// usleep(philo->time_to_eat * 1000);
	
	// drop_the_fork(philo);

	return (0);
}

int	sleeping(t_philo *philo)
{
	if (is_dead(philo))
		return (1);
	print_actions(philo, SLEEPING);
	usleep(philo->common->time_to_sleep * 1000);
	return (0);
}

int	thinking(t_philo *philo)
{
	if (is_dead(philo))
		return (1);
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
		if (its_full(philo))
			return (NULL) ;
		if (sleeping(philo))
			break ;
		if (thinking(philo))
			break ;
		// usleep(500);
	}
	return (NULL);
}