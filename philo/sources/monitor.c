/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:49:03 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/09 15:49:18 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*eye_of_horus(void *_philo)
{
	t_philo		*philos;
	size_t		curr_time;
	int			i;

	philos = (t_philo *)_philo;
	i = 0;
	while (get_stop(&philos[i]) == 0)
	{
		curr_time = get_timestamp(philos->common->start);
		if (curr_time - get_last_meal(&philos[i]) > philos->common->time_to_die)
			return (set_is_dead(philos), print_death(&philos[i], DIED), NULL);
		if (get_everyone_ate(&philos[i]) == philos->common->n_philos
			|| get_stop(&philos[i]) == 1)
			return (NULL);
		i++;
		if (i == philos->common->n_philos)
			i = 0;
		ft_usleep(1);
	}
	return (NULL);
}
