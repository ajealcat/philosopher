/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:01:45 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/31 17:10:52 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philospher.h"

int	main(int ac, char **av)
{
	t_philo		philos;
	pthread_t	new_philo;

	init_philo(philos, av);
	if (ac == 5 || ac == 6)
	{
		printf("nombre de philo = %d\n", philos.nbr_of_philo);
	}
	return (0);
}
