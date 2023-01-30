#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "defines.h"

int		main(int argc, char *argv[]);
int		check_input(int argc, char *argv[]);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
// void	get_input(t_philo *data, char **arguments);
// void	get_input(t_philo *data, char **arguments, int i);
size_t	get_time(void);
size_t	get_timestamp(size_t start);
void	*rotine(void *_philo);
// void	run_threads(pthread_t *threads, t_philo *philos, int n_philos);
void	run_threads(pthread_t *dinner, pthread_t *death, t_philo *philos, int n_philos);
void	get_input(t_philo *data, pthread_mutex_t *mtx, char **arguments, int i);
t_philo	*create_philos(int n_philos, char **arguments, pthread_mutex_t *print, pthread_mutex_t **fork);

#endif