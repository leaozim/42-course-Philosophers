/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:13:04 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/06 12:13:06 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	pick_up_forks(t_philo *philo)
{
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
