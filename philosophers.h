/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:05:21 by alelaval          #+#    #+#             */
/*   Updated: 2022/03/30 19:43:14 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>

typedef struct s_philosopher
{
	int				thread;
	int				last_eat;
	t_philosopher	prev;
	t_philosopher	next;
}				t_philosopher;

typedef struct s_philo
{
	int	time_eat;
	int	time_sleep;
	int	time_think;
	int	must_eat_x;

}				t_philo;

#endif