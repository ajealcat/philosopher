/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:01:45 by ajearuth          #+#    #+#             */
/*   Updated: 2022/02/10 17:20:41 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	destroy_mutex(t_data *data)
{
	pthread_mutex_destroy(data->time);
	pthread_mutex_destroy(data->write);
	pthread_mutex_destroy(data->death);
}

static void	free_philo(t_philo *philo)
{
	int	i;

	if (philo != NULL)
	{
		i = 0;
		while (i < philo->data->nbr_of_philo && &philo[i] != NULL)
		{
			if (philo[i].my_fork != NULL)
			{
				pthread_mutex_destroy(philo[i].my_fork);
				free(philo[i].my_fork);
			}
			if (philo[i].save != NULL)
			{
				pthread_mutex_destroy(philo[i].save);
				free(philo[i].save);
			}
			++i;
		}
	}
}

static int	destroy_and_free(t_data *data)
{
	int	i;

	i = 0;
	destroy_mutex(data);
	free_philo(data->philo);
	return (-1);
}

int	main(int ac, char **av)
{
	t_data	data;
	int i;

	i = 0;
	if (args_are_ok(ac, av) == -1)
		return (-1);
	data = init_data(&data, av);
	if (create_threads(&data) == -1)
		destroy_and_free(&data);
	while (data.someone_died == 0)
	{
		while (i < data.nbr_of_philo)
		{
			philo_died(&data.philo[i]);
			++i;
		}
	}
	destroy_and_free(&data);
	return (0);
}
