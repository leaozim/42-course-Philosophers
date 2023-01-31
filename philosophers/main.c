/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:38:14 by lade-lim          #+#    #+#             */
/*   Updated: 2023/01/31 09:38:15 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_philo(t_philo *philo)
{
	printf("1: argc = %d\n", philo->number_of_philos);
	printf("2: argc = %ld\n", philo->time_to_die);
	printf("3: argc = %ld\n", philo->time_to_eat);
	printf("4: argc = %ld\n", philo->time_to_sleep);
	printf("5: argc = %d\n", philo->must_eat);
}

int	main(int argc, char *argv[])
{
	t_philo		*philos;
	pthread_t	*dinner;
	pthread_t	death;
	t_mutex		mutex;
	t_mutex		*fork;

	fork = NULL;
	if (check_input(argc, argv))
		return (1);
	philos = create_philos(ft_atoi(argv[1]), argv, &mutex, &fork);
	if (!philos)
		return (1);
	dinner = malloc(sizeof(pthread_t) * philos[0].number_of_philos);
	if (!dinner)
		return (1);
	run_threads(dinner, &death, philos, philos[0].number_of_philos);
	return (0);
}


