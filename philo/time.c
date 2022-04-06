#include "philosphers.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	add_sleep(t_data *data, size_t time_to_sleep)
{
	size_t	time;

	time = get_time();
	while (!(data->is_dead))
	{
		if (get_time() - time >= time_to_sleep)
			break ;
		usleep(100);
	}
}

void	print_status(t_philo *philo, int num)
{
	size_t	time;

	time = get_time() - philo->share->time_init;
	pthread_mutex_lock(&philo->share->print);
	if (!philo->share->phil_die && !philo->share->eat_max)
	{
		printf("%ld", time);
		printf(" %d ", philo->id);
		if (num == 0)
			printf("has taken a fork");
		if (num == 1)
			printf("is eating");
		if (num == 2)
			printf("is sleeping");
		if (num == 3)
			printf("is thinking");
		if (num == 4)
			printf("died");
		printf("\n");
	}
	pthread_mutex_unlock(&philo->share->print);
}
