/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:58:12 by alelaval          #+#    #+#             */
/*   Updated: 2022/04/07 02:27:52 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	dead_protect(t_share *share)
{
	pthread_mutex_lock(&share->dead);
	share->is_dead = 1;
	pthread_mutex_unlock(&share->dead);
	pthread_mutex_unlock(&share->check);
}

/*
** check if a philosopher is dead
** and if they've eaten all their meal if option has been set
** if one dies the loop breaks else it continues
** until one dies or all have eaten the set ammount of meals
*/

void	is_dead(t_share *share)
{
	int	i;
	int	max;

	while (1)
	{
		i = -1;
		max = 0;
		while (!share->is_dead && ++i < share->nb_philos)
		{
			pthread_mutex_lock(&share->check);
			if (share->philos[i].dining == share->nb_eat)
				max++;
			else if (get_time() - share->philos[i].last_dine
				> (size_t)share->time_to_die)
			{
				print_status(&share->philos[i], 4);
				dead_protect(share);
				return ;
			}
			pthread_mutex_unlock(&share->check);
			usleep(100);
		}
		if (share->is_dead == 1 || max == share->nb_philos)
			return ;
	}
}

/*
** function passed at the thread creation
** delay even philosophers to spread out their starts
** execute as long as the philo isn't or hasn't finished all its meals
** eat, sleep, think
*/
void	*philo_process(void *arg)
{
	t_philo	*philo;
	t_share	*share;

	philo = (t_philo *)arg;
	share = philo->share;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		philo_eat(philo);
		if (philo->dining == share->nb_eat)
			return (NULL);
		print_status(philo, 2);
		add_sleep(share, share->time_to_sleep);
		print_status(philo, 3);
		pthread_mutex_lock(&share->dead);
		if (share->is_dead == 1)
		{
			pthread_mutex_unlock(&share->dead);
			return (NULL);
		}
		pthread_mutex_unlock(&share->dead);
	}
	return (NULL);
}

int	print_error(void)
{
	write(2, "Error: invalid arguments\n", 25);
	write(2, "Write: ./philo [philo count] [time die] [time eat]", 50);
	write(2, " [time sleep] [max eat]\n", 24);
	exit(1);
}

int	main(int ac, char **av)
{
	int			i;
	t_share		share;
	pthread_t	*t_id;

	if (ac < 5 || ac > 6 || init_philo(ac, av, &share) == 1)
		return (print_error());
	t_id = (pthread_t *)malloc(share.nb_philos * sizeof(pthread_t));
	share.time_init = get_time();
	i = -1;
	while (++i < share.nb_philos)
	{
		share.philos[i].last_dine = share.time_init;
		if (pthread_create(&t_id[i], NULL, &philo_process, &share.philos[i]))
		{
			write(2, "Error: cannot create thread\n", 28);
			free(share.philos);
			free(t_id);
			return (1);
		}
	}
	is_dead(&share);
	exit_philo(&share, t_id);
}
