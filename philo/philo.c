/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:58:12 by alelaval          #+#    #+#             */
/*   Updated: 2022/04/04 19:15:23 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	is_dead(t_share *share)
{
	int	i;

	while (!share->eat_max)
	{
		i = -1;
		while (!share->is_dead && ++i < share->nb_philos)
		{
			pthread_mutex_lock(&share->check);
			if (get_time() - share->philos[i].last_dine > (size_t)share->time_to_die)
			{
				print_status(&share->philos[i], 4);
				share->is_dead = 1;
			}
			pthread_mutex_unlock(&share->check);
			usleep(100);
		}
		if (share->is_dead)
			break ;
		i = 0;
		while (share->nb_eat != -1 && i < share->nb_philos
			&& share->philos[i].eat_count >= share->nb_eat)
			i++;
		if (i == share->nb_philos)
			share->eat_max = 1;
	}
}

void	*philo_process(void *arg)
{
	t_philo	*philo;
	t_share	*share;

	philo = (t_philo *)arg;
	share = philo->share;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!share->is_dead && !share->eat_max)
	{
		philo_eat(philo);
		print_status(philo, 2);
		add_sleep(share, share->time_to_sleep);
		print_status(philo, 3);
	}
	return (NULL);
}

int	print_error(void)
{
	write(2, "Error: invalid arguments\n", 25);
	write(2, "Write: ./philo [philo count] [time die] [time eat]", 49);
	write(2, " [time sleep] [max eat]\n", 24);
	exit(1);
}

int	main(int ac, char **av)
{
	int		i;
	t_share		*share;
	pthread_t	*t_id;
	
	if ((ac == 5 || ac == 6 ) || init_philo(ac, av, &share))
		return (print_error());
	t_id = (pthread_t *)malloc(data.n_philos * sizeof(pthread_t));
	share.time_init = get_time();
	i = -1;
	while (++i < share.nb_philos)
	{
		if (pthread_create(&t_id[i], NULL, &philo_process, &share.philos[i]))
		{
			write(2, "Error: cannot create thread\n", 28);
			free(share.philos);
			free(t_id);
			return (1);
		}
		pthread_mutex_lock(&share.check);
		share.philos[i].last_dine = share.time_init;
		pthread_mutex_unlock(&share.check);
	}
	is_dead(&share);
	exit_philo(&share, t_id);
}
