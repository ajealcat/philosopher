/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:58:09 by ajearuth          #+#    #+#             */
/*   Updated: 2022/02/15 14:41:22 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/* Your(s) program(s) should take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -sign;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb * sign);
}

t_data	init_data(t_data *data, char **av)
{
	data->nbr_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		data->stop_when = ft_atoi(av[5]);
	else
		data->stop_when = -1;
	data->someone_died = 0;
	data->eat_enough = 0;
	data->write = create_mutex();
	data->time = create_mutex();
	data->death = create_mutex();
	return (*data);
}

t_philo	init_philo(t_data *data, int i)
{
	t_philo		philo;
	pthread_t	new_thread;

	new_thread = 0;
	philo.philo_id = i;
	philo.still_alive = 1;
	philo.meal_to_eat = data->stop_when;
	philo.data = data;
	philo.last_time_eat = 0;
	philo.thread_id = new_thread;
	init_mutex(&philo);
	return (philo);
}

int	create_threads(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->nbr_of_philo);
	if (philo == NULL)
		return (-1);
	while (i < data->nbr_of_philo)
	{
		philo[i] = init_philo(data, i + 1);
		i++;
	}
	if (make_threads(data, philo) == -1)
		return (-1);
	return (1);
}

int	make_threads(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	data->philo = philo;
	find_his_fork(data->philo);
	data->departure_time = get_time();
	while (i < data->nbr_of_philo)
	{
		philo[i].last_time_eat = data->departure_time;
		if (pthread_create(&philo[i].thread_id, NULL,
				global_philo, (void *)&philo[i]) != 0)
			return (-1);
		i += 2;
	}
	i = 1;
	usleep(500);
	while (i < data->nbr_of_philo)
	{
		philo[i].last_time_eat = data->departure_time;
		if (pthread_create(&philo[i].thread_id, NULL,
				global_philo, (void *)&philo[i]) != 0)
			return (-1);
		i += 2;
	}
	return (1);
}
