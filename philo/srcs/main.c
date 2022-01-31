/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:01:45 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/31 16:43:42 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philospher.h"

int	main(int ac, char **av)
{
	t_philo		philos;
	pthread_t	new_philo;

	init_philo(philo, av);
	if (ac == 5 || ac == 6)
	{
		phthread_create(&new_philo, NULL, run_philo, NULL);
	}
}
