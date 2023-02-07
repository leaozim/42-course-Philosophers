/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:33:20 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/07 14:47:16 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*eye_of_horus(void *_philo)
{
	t_philo		*philos;
	size_t		current_time;
	int			i;

	philos = (t_philo *)_philo;
	i = 0;
	usleep(100);
	while (lock_stop(&philos[i]) == 0)
	{
		current_time = get_timestamp(philos->common->start);
		if (current_time - lock_time(&philos[i]) > philos->common->time_to_die)
			return (set_is_dead(philos), print_death(&philos[i], DIED), NULL);
		if (lock_everyone_ate(&philos[i]) == philos->common->n_philos
			|| lock_stop(&philos[i]) == 1)
			return (NULL);
		i++;
		if (i == philos->common->n_philos)
			i = 0;
	}
	return (NULL);
}

void	run_threads(t_thread *dinner, t_thread *death, t_philo *philo, int n_p)
{
	int		i;

	i = -1;
	philo->common->start = get_time();
	while (++i < n_p)
		pthread_create(&dinner[i], NULL, &rotine, (void *)&philo[i]);
	i = -1;
	pthread_create(death, NULL, &eye_of_horus, (void *)philo);
	while (++i < n_p)
		pthread_join(dinner[i], NULL);
	pthread_join(*death, NULL);
}
