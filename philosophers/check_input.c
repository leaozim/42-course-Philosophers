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
		if ((value > INT_MAX  || value == 0))
			return (1);
		i++;
	}
	return (0);
}

static	void msg_error_invald_argc(void)
{
	printf("%s\n", "Invalid number of arguments.\nUsage:\
	./philophers [number_of_philosophers [time_to_die] [time_to_eat] [time_to_eat]");
}

int	check_input(int argc, char *argv[])
{
	(void)argv;
	if (argc < 5 || argc > 6)
		return(msg_error_invald_argc(), 1);
	if (is_valid_number(argv))
		printf("Args must be unsigned integers greater than 0 and less than int max.\n");
	return (0);
}