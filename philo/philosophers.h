/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:05:21 by alelaval          #+#    #+#             */
/*   Updated: 2022/04/06 16:24:04 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_philo
{
	int				id;
	long			dining;
	long long		last_dine;
	pthread_mutex_t	fork;
	struct s_philo	*prev;
	struct s_philo	*next;
	struct s_share	*share;
}				t_philo;

typedef struct s_share
{
	long			time_to_die;
	long			time_to_sleep;
	long			time_to_eat;
	long			nb_philos;
	long			nb_eat;
	long			eat_max;
	int				is_dead;
	size_t			time_init;
	t_philo			*philos;
	pthread_mutex_t	print;
	pthread_mutex_t	check;
}				t_share;

void		exit_philo(t_share *share, pthread_t *t_id);
void		philo_eat(t_philo *philo);
int			init_philo(int ac, char *av[], t_share *share);
void		print_status(t_philo *philo, int num);
void		add_sleep(t_share *share, size_t time_to_sleep);
long		ft_atol(const char *str);
long long	get_time(void);

#endif
