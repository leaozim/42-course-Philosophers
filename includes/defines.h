#ifndef DEFINES_H
# define DEFINES_H

# include <stddef.h>
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

# define TAKE_FORK "has taken a fork\n"
# define EATING "is eating\n"
# define SLEEPING "is sleeping\n"
# define THINKING "is thinking\n"
# define DIED = "died\n"

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef pthread_mutex_t t_mutex;

typedef struct s_philo
{
	int				id;
	int				must_eat;
	int				number_of_philos;
	size_t			start;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			time_last_meal;
	t_bool			is_dead;
	t_mutex			death;
	t_mutex			*print;
	t_mutex			*left_fork;
	t_mutex			*right_fork;
}	t_philo;

// enum actions
// {
// 	EATI = 1,
// 	SLEEAP = 2,
// 	THINK = 3,
// 	DIE = 4,
// 	TAKE_FORK = 5,

// };
#endif