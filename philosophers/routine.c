#include "../includes/philosophers.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>

void	eating(t_philo *philo)
{
	printf("%-5lu %d is eating\n", get_timestamp(philo->start), philo->id);
	philo->must_eat--;
	usleep(philo->time_to_eat * 1000);
}

void	sleeping(t_philo *philo)
{
	printf("%-5lu %d is sleeping\n", get_timestamp(philo->start), philo->id);
	usleep(philo->time_to_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	printf("%-5lu %d is thinking\n", get_timestamp(philo->start), philo->id);
}

void	*rotine(void *_philo)
{
	t_philo			*philo;

	philo = (t_philo *)_philo;
	philo->start = get_time();
	while (philo->must_eat)
	{
		// pthread_mutex_lock(&philo->mutex);
		eating(philo);
		if (philo->must_eat == 0)
			break ;
		sleeping(philo);
		thinking(philo);
		// pthread_mutex_unlock(&philo->mutex);
	}
	return (NULL);
}