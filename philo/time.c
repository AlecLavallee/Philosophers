#include "philosphers.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	yousleep(int time_to_sleep, t_philo *philo)
{
	long long	actual;
	long long	end;
	int			die_time;

	actual = get_time();
	end = get_time() + time_to_sleep;
	while (actual < end)
	{
		pthread_mutex_lock(&philo->share->dead_mutex);
		die_time = philo->share->die_time;
		pthread_mutex_unlock(&philo->share->dead_mutex);
		if (die_time == 0)
			return ;
		usleep(100);
		actual = get_time();
	}
}
