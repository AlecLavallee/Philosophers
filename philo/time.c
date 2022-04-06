/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:33:58 by alelaval          #+#    #+#             */
/*   Updated: 2022/04/06 21:07:11 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	add_sleep(t_share *share, size_t time_to_sleep)
{
	size_t	time;

	time = get_time();
	while (!(share->is_dead))
	{
		if (get_time() - time >= time_to_sleep)
			break ;
		usleep(100);
	}
}
