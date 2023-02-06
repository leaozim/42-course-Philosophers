/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:38:02 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/06 12:10:06 by lade-lim         ###   ########.fr       */
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
			if (nbr[i][j] == '+' && j == 0)
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
	printf(" ____________________________________________________ \n");
	printf("|                                                    |\n");
	printf(RED"|            Please enter 4 or 5 arguments           |\n"RESET);
	printf("|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |\n");
	printf("|                                                    |\n");
	printf("|             [1][Number of philosophers]            |\n");
	printf("|             [2][Time to die]                       |\n");
	printf("|             [3][Time to eat]                       |\n");
	printf("|             [4][Time to sleep]                     |\n");
	printf("|             [5][Number of meals]                   |\n");
	printf("|____________________________________________________|\n");
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
