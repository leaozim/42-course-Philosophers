#include "../includes/philosophers.h"

void	print_actions(t_philo *philo, char *action)
{
	pthread_mutex_lock(philo->print);
	printf("%-5lu %d %s", get_timestamp(philo->start), philo->id, action);	
	pthread_mutex_unlock(philo->print);
}

void	pick_up_the_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	print_actions(philo, TAKE_FORK);
	print_actions(philo, TAKE_FORK);
	// printf("%-5lu %d  has taken a fork \n", get_timestamp(philo->start), philo->id);	
	// pthread_mutex_unlock(philo->print);
}

void	drop_the_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	eating(t_philo *philo)
{
	pick_up_the_fork(philo);
	print_actions(philo, EATING);
	philo->must_eat--;
	philo->time_last_meal = get_time();
	usleep(philo->time_to_eat * 1000);
	drop_the_fork(philo);
}

void	sleeping(t_philo *philo)
{
	print_actions(philo, SLEEPING);
	usleep(philo->time_to_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	print_actions(philo, THINKING);
}

void	*rotine(void *_philo)
{
	t_philo			*philo;

	philo = (t_philo *)_philo;
	while (philo->must_eat)
	{
		eating(philo);
		if (philo->must_eat == 0 || philo->is_dead == TRUE)
			break ;
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}