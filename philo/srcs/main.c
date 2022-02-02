/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:01:45 by ajearuth          #+#    #+#             */
/*   Updated: 2022/02/02 11:55:54 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char **av)
{
	t_philo philos;

	if (args_are_ok(ac, av) == -1)
		return (-1);
	philos = init_philo(&philos, av);
	printf("nombre de philo = %d\n", philos.nbr_of_philo);
	printf("tt die = %d\n", philos.time_to_die);
	printf("tt eat = %d\n", philos.time_to_eat);
	printf("tt sleep = %d\n", philos.time_to_sleep);
	printf("stop = %d\n", philos.stop_when);
	return (0);
}
