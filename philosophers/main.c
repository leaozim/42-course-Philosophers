/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:38:14 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/02 10:20:21 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_philo(t_philo *philo)
{
	printf("1: argc         = %d\n", philo->common->number_of_philos);
	printf("2: argc         = %ld\n", philo->common->time_to_die);
	printf("3: argc         = %ld\n", philo->common->time_to_eat);
	printf("4: argc         = %ld\n", philo->common->time_to_sleep);
	printf("5: argc         = %d\n", philo->common->must_eat);
	printf("time_last_mealc = %ld\n", philo->time_last_meal);
	int i = 0;
	while (philo->common->number_of_philos > i)
	{
		printf("id         = %d\n", philo[i].id);
		printf("id_dead    = %d\n", philo[i].is_dead);
		printf("start      = %ld\n",philo[i].common->start);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_philo		*philos;
	pthread_t	*dinner;
	pthread_t	death;
	t_mutex		*fork;
	t_common	common;

	fork = NULL;
	
	if (check_input(argc, argv))
		return (1);
	philos = create_philos(ft_atoi(argv[1]), argv, &common, &fork);
	if (!philos)
		return (1);
	// print_philo(philos); 
	dinner = malloc(sizeof(pthread_t) * common.number_of_philos);
	if (!dinner)
		return (1);
	run_threads(dinner, &death, philos, common.number_of_philos);
	return (0);
}


