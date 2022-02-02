/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:01:45 by ajearuth          #+#    #+#             */
/*   Updated: 2022/02/02 16:03:10 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	destroy_and_free(t_data data)
{
	
}

int	main(int ac, char **av)
{
	t_data data;

	if (args_are_ok(ac, av) == -1)
		return (-1);
	data = init_data(&data, av);
	create_threads(&data);
	printf("nombre de philo = %d\n", data.nbr_of_philo);
	printf("tt die = %d\n", data.time_to_die);
	printf("tt eat = %d\n", data.time_to_eat);
	printf("tt sleep = %d\n", data.time_to_sleep);
	printf("stop = %d\n", data.stop_when);
	return (0);
}
