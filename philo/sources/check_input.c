/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:38:02 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/09 15:23:00 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static	int	is_valid_number(char *nbr[])
{
	int				i;
	int				j;
	unsigned int	value;

	i = 1;
	while (nbr[i])
	{
		j = 0;
		if (ft_strlen(nbr[i]) > 11)
			return (1);
		while (nbr[i][j])
		{
			if (nbr[i][j] == PLUS && j == 0)
				j++;
			if (!ft_isdigit(nbr[i][j]))
				return (1);
			j++;
		}
		value = (unsigned int)ft_atoi(nbr[i]);
		if ((value > INT_MAX || value == 0))
			return (1);
		i++;
	}
	return (0);
}

static	void	msg_error_invald_argc(void)
{
	printf(RED" ____________________________________________________ \n"RESET);
	printf(RED"|                                                    |\n"RESET);
	printf(RED"|            Please enter 4 or 5 arguments           |\n"RESET);
	printf(RED"|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |\n"RESET);
	printf(RED"|                                                    |\n"RESET);
	printf(RED"|             [1][Number of philosophers]            |\n"RESET);
	printf(RED"|             [2][Time to die]                       |\n"RESET);
	printf(RED"|             [3][Time to eat]                       |\n"RESET);
	printf(RED"|             [4][Time to sleep]                     |\n"RESET);
	printf(RED"|             [5][Number of meals]                   |\n"RESET);
	printf(RED"|____________________________________________________|\n"RESET);
}

int	check_input(int argc, char *argv[])
{
	(void)argv;
	if (argc < 5 || argc > 6)
		return (msg_error_invald_argc(), 1);
	if (is_valid_number(argv))
		return (printf(RED"%s"RESET, ERROR_MSG), 1);
	return (0);
}
