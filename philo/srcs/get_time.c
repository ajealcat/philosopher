/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:58:27 by ajearuth          #+#    #+#             */
/*   Updated: 2022/02/04 13:10:25 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long int	get_time(void)
{
	long int		ms;
	struct timeval	time;

	ms = 0;
	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void	print_status(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->data->write);
	pthread_mutex_lock(philo->data->time);
	printf("%ld philo %d %s", get_time(), philo->philo_id, str);
	pthread_mutex_unlock(philo->data->write);
	pthread_mutex_unlock(philo->data->time);
}
