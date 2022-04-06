#include "philosophers.h"

void	init_share(t_share *share)
{
	int	i;

	share->is_dead = 0;
	share->eat_max = 0;
	share->philos = (t_philo *)malloc(share->nb_philos * sizeof(t_philo));
	i = -1;
	while (++i < share->nb_philos)
	{
		share->philos[i].id = i + 1;
		share->philos[i].share = share;
		share->philos[i].dining = 0;
		if (i + 1 == share->nb_philos)
			share->philos[i].prev = &share->philos[0];
		else
			share->philos[i].prev = &share->philos[i + 1];
		if (i == 0)
			share->philos[i].next = &share->philos[share->nb_philos - 1];
		else
			share->philos[i].next = &share->philos[i - 1];
		pthread_mutex_init(&share->philos[i].fork, NULL);
	}
	pthread_mutex_init(&share->print, NULL);
	pthread_mutex_init(&share->check, NULL);
}

int	init_philo(int ac, char *av[], t_share *share)
{
	if (check_arg(ac, av))
		return (1);
	share->nb_philos = ft_atol(av[1]);
	share->time_to_die = ft_atol(av[2]);
	share->time_to_eat = ft_atol(av[3]);
	share->time_to_sleep = ft_atol(av[4]);
	share->nb_eat = -1;
	if (ac == 6)
		share->nb_eat = ft_atol(av[5]);
	init_share(share);
	return (0);
}
