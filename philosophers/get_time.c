/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:38:07 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/07 15:00:03 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

size_t	get_timestamp(size_t start)
{
	return (get_time() - start);
}

void	ft_usleep(int ms)
{
	size_t	time;

	time = get_time();
	while (get_time() - time < (size_t)ms)
		usleep(10);
}
