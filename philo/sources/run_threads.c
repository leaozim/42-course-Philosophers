/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:33:20 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/10 10:35:30 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	msg_error(char *error)
{
	printf("%s\n", error);
}

static t_bool	join_threads(pthread_t *dinner, int n_philos)
{
	int	i;

	i = -1;
	while (++i < n_philos)
		if (pthread_join(dinner[i], NULL) != 0)
			return (FALSE);
	return (TRUE);
}

static t_bool	create_threads(t_philo *philo, pthread_t *dinner, int n_philos)
{
	int	i;

	i = -1;
	while (++i < n_philos)
		if (pthread_create(&dinner[i], NULL, &rotine, (void *)&philo[i]) != 0)
			return (FALSE);
	return (TRUE);
}

t_bool	run_threads(t_thread *dinner, t_thread *death, t_philo *philo, int n_p)
{
	philo->common->start = get_time();
	if (!create_threads(philo, dinner, n_p))
		return (msg_error(THREAD_ERROR), FALSE);
	if (pthread_create(death, NULL, &eye_of_horus, (void *)philo) != 0)
		return (msg_error(THREAD_ERROR2), FALSE);
	if (!join_threads(dinner, n_p))
		return (msg_error(JOIN_ERROR2), FALSE);
	if (pthread_join(*death, NULL) != 0)
		return (msg_error(JOIN_ERROR), FALSE);
	return (TRUE);
}
