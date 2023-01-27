#include "../includes/philosophers.h"

void	print_philo(t_philo *philo)
{
	printf("1: argc = %d\n", philo->number_of_philos);
	printf("2: argc = %d\n", philo->time_to_die);
	printf("3: argc = %d\n", philo->time_to_eat);
	printf("4: argc = %d\n", philo->time_to_sleep);
	printf("5: argc = %d\n", philo->must_eat);
}

t_philo	*create_philos(int n_philos, char **arguments, pthread_mutex_t *mutex)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(t_philo) * n_philos);
	while (i < n_philos)
	{
		get_input(&philos[i], mutex, arguments, i);
		i++;
	}
	return (philos);
}

void	run_threads(pthread_t *threads, t_philo *philos, int n_philos)
{
	int i;

	i = 0;
	pthread_mutex_init(philos->mutex, NULL);
	while (i < n_philos)
	{
		pthread_create(&threads[i], NULL, &rotine, &philos[i]);
		i++;
	}
	i = 0;
	while (i < n_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	pthread_mutex_destroy(philos->mutex);
}

int	main(int argc, char *argv[])
{
	t_philo			*philos;
	pthread_t		*threads;
	pthread_mutex_t	mutex;

	if (check_input(argc, argv))
		return (1);
	philos = create_philos(ft_atoi(argv[1]), argv, &mutex);
	if (!philos)
		return (1);
	threads = malloc(sizeof(pthread_t) * philos[0].number_of_philos);
	if (!threads)
		return (1);
	run_threads(threads, philos, philos[0].number_of_philos);
	return (0);
}


