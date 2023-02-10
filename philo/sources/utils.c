/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:37:57 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/06 12:20:39 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	negative;
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	negative = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			negative = negative * -1;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i++] - '0';
	}
	return (res * negative);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	id;

	id = 0;
	while ((s1[id] != '\0') && (s2[id] != '\0') && s1[id] == s2[id])
		id++;
	return ((unsigned char)s1[id] - (unsigned char)s2[id]);
}
