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

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef struct s_philo
{
	int				number_of_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				must_eat;
	int				id;
	t_bool			is_dead;
	size_t			start;
	size_t			time_last_meal;
	pthread_mutex_t death;
	pthread_mutex_t	*print;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
}	t_philo;


#endif