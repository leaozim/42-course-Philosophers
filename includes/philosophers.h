#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "defines.h"
# include "printf_colors.h"

int		main(int argc, char *argv[]);
int		check_input(int argc, char *argv[]);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
size_t	get_time(void);
size_t	get_timestamp(size_t start);
void	*rotine(void *_philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	print_actions(t_philo *philo, char *action);
void	ft_usleep(int ms);
void	run_threads(t_thread *dinner, t_thread *death, t_philo *philos, int n_p);
void	get_input(t_philo *data, pthread_mutex_t *mtx, int i);
void	*eye_of_horus(void *_philo);
t_bool	travar(t_philo *philo);
t_philo	*create_philos(int n_p, char **argcs, t_common *common, t_mutex **fork);
int		is_satiated(t_philo *philo);
t_bool	its_full(t_philo *philo);
t_bool	is_dead(t_philo *philo);
int		ft_strcmp(char *s1, char *s2);
void	print_death(t_philo *philo, char *action);
void	ft_usleep(int ms);
int		lock_stop(t_philo	*philo);
int		lock_is_dead(t_philo *philo);
int		lock_meals_eaten(t_philo	*philo);
int		lock_everyone_ate(t_philo	*philo);
void	set_is_dead(t_philo *philos);
size_t	lock_time(t_philo	*philo);
void	destroy_philosophers(t_philo *philos, t_thread *dinner, t_mutex **fork);
#endif