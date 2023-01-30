#include "../includes/philosophers.h"

void	eating(t_philo *philo)
{

	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->print);

	// printf("%ld\n", get_time() - philo->time_last_meal);
	printf("%-5lu %d fork \n", get_timestamp(philo->start), philo->id);	
	printf("%-5lu %d fork \n", get_timestamp(philo->start), philo->id);	
	printf("%-5lu %d is eating\n", get_timestamp(philo->start), philo->id);
	philo->must_eat--;
	philo->time_last_meal = get_time();
	pthread_mutex_unlock(philo->print );
	usleep(philo->time_to_eat * 1000);
	
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);

}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%-5lu %d is sleeping\n", get_timestamp(philo->start), philo->id);
	pthread_mutex_unlock(philo->print );
	usleep(philo->time_to_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%-5lu %d is thinking\n", get_timestamp(philo->start), philo->id);
	pthread_mutex_unlock(philo->print);
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