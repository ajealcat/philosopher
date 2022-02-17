/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:58:27 by ajearuth          #+#    #+#             */
/*   Updated: 2022/02/17 14:57:49 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long int	get_time(void)
{
	long int		ms;
	struct timeval	time;

	ms = 0;
	if (gettimeofday(&time, NULL) == -1)
	{
		ft_putstr_fd("Error: gettimeofday error.\n", 2);
		return (-1);
	}
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void	print_status(t_philo *philo, char *str)
{
	if (check_death(philo) == -1)
		return ;
	pthread_mutex_lock(philo->data->time);
	pthread_mutex_lock(philo->data->write);
	printf("%ld philo %d %s", get_time() - philo->data->departure_time,
		philo->philo_id, str);
	pthread_mutex_unlock(philo->data->time);
	pthread_mutex_unlock(philo->data->write);
}

void	my_usleep(t_philo *philo, long int timing)
{
	long int	count;

	pthread_mutex_lock(philo->data->time);
	pthread_mutex_lock(philo->data->death);
	count = get_time();
	while (philo->data->someone_died == 0 && get_time() < count + timing)
	{
		pthread_mutex_unlock(philo->data->death);
		pthread_mutex_unlock(philo->data->time);
		usleep(500);
		pthread_mutex_lock(philo->data->time);
		pthread_mutex_lock(philo->data->death);
	}
	pthread_mutex_unlock(philo->data->death);
	pthread_mutex_unlock(philo->data->time);
}

void	for_the_norm(t_philo *philo)
{
	pthread_mutex_lock(philo->data->full);
	++philo->data->eat_enough;
	pthread_mutex_unlock(philo->data->full);
	pthread_mutex_unlock(philo->my_fork);
	pthread_mutex_unlock(philo->his_fork);
	pthread_mutex_unlock(philo->save);
}
