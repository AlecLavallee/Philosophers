/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:05:21 by alelaval          #+#    #+#             */
/*   Updated: 2022/04/04 20:40:44 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>

typedef struct s_info
{
	long			time_to_die;
	long			time_to_sleep;
	long			time_to_eat;
	long long		start_time;
	pthread_mutex_t	dying;
	pthread_mutex_t eating;
}				t_info;

typedef struct s_philosopher
{
	int				id;
	long			dining;
	long long		last_dine;
	t_info			*info;
	pthread_mutex_t	mutex;
	pthread_t		thread;
	t_philosopher	*prev;
	t_philosopher	*next;
}				t_philosopher;

#endif
