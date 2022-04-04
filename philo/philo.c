/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:58:12 by alelaval          #+#    #+#             */
/*   Updated: 2022/04/04 19:15:23 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_atol(long nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 10)
	{
		ft_putchar(nb % 10 + 48);
		ft_atol(nb);
	}
	else
		ft_putchar(putchar + 48);
}
int	main(int ac, char **av)
{
	t_info	*
	if (ac == 5 || ac == 6)
	{
		check_args()
	}
}
