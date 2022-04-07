/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:56:01 by alelaval          #+#    #+#             */
/*   Updated: 2022/04/07 01:34:52 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 
**philo tries to take his/her fork in its hand
** and the one from the previous philosopher
** after philo gets to sleep
*/

void	philo_eat(t_philo *philo)
{
	t_share	*share;

	share = philo->share;
	if (philo->share->nb_philos == 1)
	{
		add_sleep(share, share->time_to_die);
		print_status(philo, 4);
		share->is_dead = 1;
		return ;
	}
	pthread_mutex_lock(&philo->fork);
	print_status(philo, 0);
	pthread_mutex_lock(&philo->prev->fork);
	print_status(philo, 0);
	pthread_mutex_lock(&share->check);
	print_status(philo, 1);
	philo->dining++;
	philo->last_dine = get_time();
	pthread_mutex_unlock(&share->check);
	add_sleep(share, share->time_to_eat);
	pthread_mutex_unlock(&philo->prev->fork);
	pthread_mutex_unlock(&philo->fork);
}
