/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:33:20 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/07 10:34:03 by lade-lim         ###   ########.fr       */
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
		{
			set_is_dead(philos);
			pthread_mutex_lock(philos->common->print);
			printf("%-5lu %d  the cat is die\n", get_timestamp(philos->common->start), philos[i].id);
			pthread_mutex_unlock(philos->common->print);
			return (NULL) ; 
		}
		if (lock_everyone_ate(&philos[i]) == philos->common->number_of_philos || lock_stop(&philos[i]) == 1)
			return (NULL) ;
		i++;
		if (i == philos->common->number_of_philos)
			i = 0;
		ft_usleep(1);
	}
	return (NULL);
	
}

void	run_threads(t_thread *dinner, t_thread *death, t_philo *philos, int n_p)
{
	int		i;

	i = -1;
	philos->common->start = get_time();
	while (++i < n_p)
		pthread_create(&dinner[i], NULL, &rotine, (void *)&philos[i]);
	i = -1;
	pthread_create(death, NULL, &eye_of_horus, (void *)philos);
	while (++i < n_p)
		pthread_join(dinner[i], NULL);
	pthread_join(*death, NULL);
}
