/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:22:45 by alelaval          #+#    #+#             */
/*   Updated: 2022/04/06 21:07:08 by alelaval         ###   ########.fr       */
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

	time = get_time() - philo->share->time_init;
	pthread_mutex_lock(&philo->share->print);
	if (!philo->share->is_dead && !philo->share->eat_max)
	{
		printf("%lu", time);
		printf(" %d ", philo->id);
		if (num == 0)
			printf("has taken a fork");
		if (num == 1)
			printf("is eating");
		if (num == 2)
			printf("is sleeping");
		if (num == 3)
			printf("is thinking");
		if (num == 4)
			printf("died");
		printf("\n");
	}
	pthread_mutex_unlock(&philo->share->print);
}
