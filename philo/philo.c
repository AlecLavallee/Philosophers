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

int	print_error(void)
{
	write(2, "Error: invalid arguments\n", 25);
	write(2, "Write: ./philo [philo count] [time die] [time eat]", 49);
	write(2, " [time sleep] [max eat]\n", 24);
	exit(1);
}

int	main(int ac, char **av)
{
	t_info	*
	if (ac == 5 || ac == 6)
	{
		check_args()
	}
}
