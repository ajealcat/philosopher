/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:01:45 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/31 16:37:03 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philospher.h"

int	main(int ac, char **av)
{
	t_philo		philos;
	pthread_t	new_philo;
	int			i;

	i = 0;
	if (ac == 5 || ac == 6)
	{
		i = ft_atoi(av[1]);
		while (i)
		{
			init_philo(philo, av);
			--i;
		}
		phthread_create(&new_philo, NULL, run_philo, NULL);
	}
}
