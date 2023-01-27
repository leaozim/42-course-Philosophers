#ifndef DEFINES_H
# define DEFINES_H

#include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define INT_MAX 2147483647
# define INT_MIN_NO_SING 2147483648
# define INT_MIN -2147483648 
# define LESS '-'
# define PLUS '+'

typedef struct s_philo
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				id;
	size_t			start;
	pthread_mutex_t	mutex;

}	t_philo;


#endif