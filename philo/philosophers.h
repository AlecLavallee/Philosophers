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

# include <unistd.h>
# include <errno.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int			id;
	long			dining;
	long long		last_dine;
	pthread_mutex_t		fork;
	struct s_philo		*prev;
	struct s_philo		*next;
	struct s_share		*share;
}				t_philo;

typedef struct s_share
{
	long			time_to_die;
	long			time_to_sleep;
	long			time_to_eat;
	long long		start_time;
	long long		nb_philos;
	long long		eat_max;
	int			is_deadl
	size_t			time_init;
	t_philo			*philos;
	pthread_mutex_t		print;
	pthread_mutex_t		check;
}				t_share;

#endif
