/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:57:32 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/09 15:36:01 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "defines.h"
# include "printf_colors.h"

void	get_input(t_philo *data, pthread_mutex_t *mtx, int i);
int		check_input(int argc, char *argv[]);
t_philo	*create_philos(int n_p, char **argcs, t_common *common, t_mutex **fork);
t_bool	run_threads(t_thread *dinner, t_thread *death, t_philo *philo, int n_p);
void	*rotine(void *_philo);
void	*eye_of_horus(void *_philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	print_actions(t_philo *philo, char *action);
void	print_death(t_philo *philo, char *action);
size_t	get_time(void);
size_t	get_timestamp(size_t start);
void	ft_usleep(int ms);
int		get_stop(t_philo	*philo);
size_t	get_last_meal(t_philo	*philo);
int		get_is_dead(t_philo *philo);
int		get_meals_eaten(t_philo	*philo);
int		get_everyone_ate(t_philo	*philo);
void	set_is_dead(t_philo *philos);
int		is_satiated(t_philo *philo);
t_bool	is_dead(t_philo *philo);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
void	destroy_philosophers(t_philo *philos, t_thread *dinner, t_mutex **fork);

#endif