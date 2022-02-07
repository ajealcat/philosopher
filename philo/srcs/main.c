/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:01:45 by ajearuth          #+#    #+#             */
/*   Updated: 2022/02/07 17:01:37 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	destroy_mutex(t_data *data)
{
	pthread_mutex_destroy(data->time);
	pthread_mutex_destroy(data->write);
	pthread_mutex_destroy(data->philo->my_fork);
	pthread_mutex_destroy(data->philo->his_fork);
	pthread_mutex_destroy(data->philo->save);
}

static  void free_philo(t_philo *philo)
{
	
}

static int	destroy_and_free(t_data *data)
{
	destroy_mutex(data);
	return (-1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (args_are_ok(ac, av) == -1)
		return (-1);
	data = init_data(&data, av);
	if (create_threads(&data) == -1)
		destroy_and_free(&data);
	usleep(5000000);
	return (0);
}
