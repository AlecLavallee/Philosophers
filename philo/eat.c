/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:56:01 by alelaval          #+#    #+#             */
/*   Updated: 2022/03/30 19:57:37 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_philo *philo)
{
	t_share	*share;

	share = philo->share;
	pthread_mutex_lock(&philo->fork);
	print_status(philo, 0);
	if (philo->share->nb_philos == 1)
	{
		add_sleep(data, data->t_die);
		print_status(philo, 4);
		pthread_mutex_unlock(&philo->fork);
		data->is_dead = 1;
		return ;
	}
	pthread_mutex_lock(&philo->prev->fork);
	print_status(philo, 0);
	pthread_mutex_lock(&share->check);
	philo->dining++;
	print_status(philo, 1);
	philo->last_dine = get_time();
	pthread_mutex_unlock(&share->check);
	add_sleep(share, share->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->prev->fork);
}
