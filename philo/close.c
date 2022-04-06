/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:44:20 by alelaval          #+#    #+#             */
/*   Updated: 2022/04/06 16:19:45 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	exit_philo(t_share *share, pthread_t *t_id)
{
	int		i;
	t_philo	*next;

	i = 0;
	while (i < share->nb_philos)
	{
		pthread_join(t_id[i], NULL);
		i++;
	}
	next = NULL;
	while (share->philos->next)
	{
		next = share->philos->next;
		free(share->philos);
	}
	free (next);
}
