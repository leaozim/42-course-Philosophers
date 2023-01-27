#include "../includes/philosophers.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	printf("%-5lu %d is eating\n", get_timestamp(philo->start), philo->id);
	philo->must_eat--;
	pthread_mutex_unlock(philo->mutex );
	usleep(philo->time_to_eat * 1000);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	printf("%-5lu %d is sleeping\n", get_timestamp(philo->start), philo->id);
	pthread_mutex_unlock(philo->mutex );
	usleep(philo->time_to_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	printf("%-5lu %d is thinking\n", get_timestamp(philo->start), philo->id);
	pthread_mutex_unlock(philo->mutex);
}

void	*rotine(void *_philo)
{
	t_philo			*philo;

	philo = (t_philo *)_philo;
	philo->start = get_time();
	while (philo->must_eat)
	{
		eating(philo);
		if (philo->must_eat == 0)
			break ;
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}