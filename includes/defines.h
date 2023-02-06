/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:57:32 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/06 17:31:37 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define TAKE_FORK	"has taken a fork\n"
# define EATING		"is eating\n"
# define SLEEPING	"is sleeping\n"
# define THINKING	"is thinking\n"
# define DIED 		"died\n"
# define ERROR_MSG "Args must be unsigned integers greater than 0!\n"

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_thread;

typedef struct s_common
{
	int				is_dead;
	int				must_eat;
	int				everyone_ate;
	int				number_of_philos;
	size_t			start;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	t_mutex			*print;
	t_mutex			*death;
	t_mutex			*look_is_dead;
}	t_common;

typedef struct s_philo
{
	int				id;
	int				meals;
	int				meals_eaten;
	int				stop;
	int				stop_while;
	size_t			time_last_meal;
	size_t			time_of_death;
	size_t			time_start;
	t_mutex			*look_current_time;
	t_mutex			*look_start;
	t_mutex			*look_stop;
	t_mutex			*lock_meals;
	t_mutex			*look_meals_eaten;
	t_mutex			*left_fork;
	t_mutex			*right_fork;
	t_common		*common;
}	t_philo;

#endif