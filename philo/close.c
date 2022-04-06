/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:44:20 by alelaval          #+#    #+#             */
/*   Updated: 2022/04/06 18:24:22 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	exit_philo(t_share *share, pthread_t *t_id)
{
	int		i;

	i = -1;
	while (++i < share->nb_philos)
		pthread_join(t_id[i], NULL);
	i = -1;
	while (++i < share->nb_philos)
		pthread_mutex_destroy(&share->philos[i].fork);
	pthread_mutex_destroy(&share->print);
	pthread_mutex_destroy(&share->check);
}
