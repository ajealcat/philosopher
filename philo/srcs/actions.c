/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:56:43 by ajearuth          #+#    #+#             */
/*   Updated: 2022/02/07 16:15:48 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(philo->my_fork);
	print_status(philo, "has taken a fork.\n");
	pthread_mutex_lock(philo->his_fork);
	print_status(philo, "has taken another fork.\n");
}

void	philo_eat(t_philo *philo)
{
	print_status(philo, "is eating.\n");
	my_usleep(philo, philo->data->time_to_eat);
	pthread_mutex_unlock(philo->my_fork);
	pthread_mutex_unlock(philo->his_fork);
	pthread_mutex_lock(philo->data->time);
	pthread_mutex_lock(philo->save);
	philo->last_time_eat = get_time();
	pthread_mutex_unlock(philo->data->time);
	pthread_mutex_unlock(philo->save);
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping.\n");
	my_usleep(philo, philo->data->time_to_sleep);
	print_status(philo, "is thinking.\n");
}

void	*global_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->data->someone_died == 0)
	{
		philo_think(philo);
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (philo);
}
