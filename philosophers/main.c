/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:38:14 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/07 10:44:41 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char *argv[])
{
	t_thread	*dinner;
	t_thread	death;
	t_common	common;
	t_mutex		*fork;
	t_philo		*philos;

	fork = NULL;
	if (check_input(argc, argv))
		return (1);
	philos = create_philos(ft_atoi(argv[1]), argv, &common, &fork);
	if (!philos)
		return (1);
	dinner = malloc(sizeof(pthread_t) * common.n_philos);
	if (!dinner)
		return (1);
	run_threads(dinner, &death, philos, common.n_philos);
	destroy_philosophers(philos, dinner, &fork);
	return (0);
}
