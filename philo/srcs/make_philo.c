/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:37:15 by ajearuth          #+#    #+#             */
/*   Updated: 2022/02/15 16:47:16 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*global_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->data->death);
	pthread_mutex_lock(philo->save);
	if (philo->data->stop_when != -1)
	{
		if (habits_launcher(philo) == -1)
			return ((void *)-1);
	}
	else if (philo->data->stop_when == -1)
	{
		if (habits_launcher(philo) == -1)
			return ((void *)-1);
	}
	return (philo);
}

int	habits_launcher(t_philo *philo)
{
	while (philo->data->someone_died == 0)
	{
		pthread_mutex_unlock(philo->data->death);
		pthread_mutex_unlock(philo->save);
		if (philo->philo_id % 2 == 0)
		{
			if (make_pair_philo(philo) == -1)
				return (-1);
		}
		else
		{
			if (make_odd_philo(philo) == -1)
				return (-1);
		}
		pthread_mutex_lock(philo->data->death);
		pthread_mutex_lock(philo->save);
	}
	pthread_mutex_unlock(philo->data->death);
	pthread_mutex_unlock(philo->save);
	return (0);
}

int	make_pair_philo(t_philo *philo)
{
	if (check_death(philo) == -1)
		return (-1);
	else
		philo_pair(philo);
	if (check_death(philo) == -1)
	{
		pthread_mutex_unlock(philo->my_fork);
		pthread_mutex_unlock(philo->his_fork);
		return (-1);
	}
	else
		philo_eat(philo);
	pthread_mutex_lock(philo->save);
	if (philo->meal_to_eat == 0)
	{
		pthread_mutex_lock(philo->data->full);
		++philo->data->eat_enough;
		pthread_mutex_unlock(philo->data->full);
		pthread_mutex_unlock(philo->my_fork);
		pthread_mutex_unlock(philo->his_fork);
		pthread_mutex_unlock(philo->save);
		return (-1);
	}
	pthread_mutex_unlock(philo->save);
	if (check_death(philo) == -1)
		return (-1);
	else
		philo_sleep(philo);
	return (0);
}

int	make_odd_philo(t_philo *philo)
{
	if (check_death(philo) == -1)
		return (-1);
	else
		philo_odd(philo);
	if (check_death(philo) == -1)
	{
		pthread_mutex_unlock(philo->my_fork);
		if (philo->his_fork != NULL)
			pthread_mutex_unlock(philo->his_fork);
		return (-1);
	}
	else
		philo_eat(philo);
	pthread_mutex_lock(philo->save);
	if (philo->meal_to_eat == 0)
	{
		pthread_mutex_lock(philo->data->full);
		++philo->data->eat_enough;
		pthread_mutex_unlock(philo->data->full);
		pthread_mutex_unlock(philo->my_fork);
		pthread_mutex_unlock(philo->his_fork);
		pthread_mutex_unlock(philo->save);
		return (-1);
	}
	pthread_mutex_unlock(philo->save);
	if (check_death(philo) == -1)
		return (-1);
	else
		philo_sleep(philo);
	return (0);
}

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(philo->data->death);
	if (philo->data->someone_died == 1)
	{
		pthread_mutex_unlock(philo->data->death);
		return (-1);
	}
	pthread_mutex_unlock(philo->data->death);
	return (0);
}
