/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:38:19 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/03 17:56:53 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include <stddef.h>
#include <stdio.h>

// int	set_current_time(t_philo *philo)
// {
// 	long	current_time;

// 	pthread_mutex_lock(philo->);
// 	current_time = philo->;
// 	pthread_mutex_unlock(philo->lock_supper);
// 	return (lastsupper);
// }

void	set_lastsupper(t_philo *philo)
{
	pthread_mutex_lock(philo->look_current_time);
	philo->time_start = get_timestamp(philo->common->start);
	pthread_mutex_unlock(philo->look_current_time);
}

void	ft_usleep(int ms)
{
	size_t	time;

	time = get_time();
	while( get_time() - time < (size_t)ms)
		usleep(10);
	// while (get_time() < time + ms)
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

static void	pick_up_forks(t_philo *philo)
{
	// size_t current_time;

	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	if (lock_stop(philo) != 1)
	{
		print_actions(philo, TAKE_FORK);
		print_actions(philo, TAKE_FORK);
	}
	else if (lock_stop(philo) == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}

static void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	eating(t_philo *philo)
{
	pick_up_forks(philo);
	print_actions(philo, EATING);
	pthread_mutex_lock(philo->lock_meals);
	philo->time_last_meal = get_timestamp(philo->common->start);
	pthread_mutex_unlock(philo->lock_meals);
	ft_usleep(philo->common->time_to_eat);
	drop_forks(philo);
	pthread_mutex_lock(philo->look_meals_eaten);
	philo->meals_eaten += 1;
	pthread_mutex_unlock(philo->look_meals_eaten);
}

void	sleeping(t_philo *philo)
{
	print_actions(philo, SLEEPING);
	ft_usleep(philo->common->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_actions(philo, THINKING);
	usleep(500);
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