/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:22:45 by alelaval          #+#    #+#             */
/*   Updated: 2022/04/07 01:33:36 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

long	ft_atol(const char *str)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb < 0 && sign == 1)
			return (-1);
		else if (nb < 0 && sign != 1)
			return (0);
		i++;
	}
	if (nb < 0)
		return (-1);
	return (sign * nb);
}

void	print_status(t_philo *philo, int num)
{
	size_t	time;
	int		tmp;

	time = get_time() - philo->share->time_init;
	pthread_mutex_lock(&philo->share->print);
	pthread_mutex_lock(&philo->share->dead);
	tmp = philo->share->is_dead;
	pthread_mutex_unlock(&philo->share->dead);
	if (tmp == 0)
	{
		printf("%lu", time);
		printf(" %d ", philo->id);
		if (num == 0)
			printf("has taken a fork\n");
		if (num == 1)
			printf("is eating\n");
		if (num == 2)
			printf("is sleeping\n");
		if (num == 3)
			printf("is thinking\n");
		if (num == 4)
			printf("died\n");
	}
	pthread_mutex_unlock(&philo->share->print);
}
