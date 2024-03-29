/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:56:43 by ajearuth          #+#    #+#             */
/*   Updated: 2022/02/17 15:08:41 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	philo_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->my_fork);
	print_status(philo, "has taken his fork.\n");
	if (philo->his_fork != NULL)
		pthread_mutex_lock(philo->his_fork);
	else
	{
		my_usleep(philo, philo->data->time_to_die * 2);
		return ;
	}
	print_status(philo, "has taken a fork.\n");
}

void	philo_pair(t_philo *philo)
{
	if (philo->his_fork != NULL)
		pthread_mutex_lock(philo->his_fork);
	print_status(philo, "has taken a fork.\n");
	pthread_mutex_lock(philo->my_fork);
	print_status(philo, "has taken his fork.\n");
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->data->time);
	pthread_mutex_lock(philo->save);
	philo->last_time_eat = get_time();
	pthread_mutex_unlock(philo->data->time);
	--philo->meal_to_eat;
	pthread_mutex_unlock(philo->save);
	print_status(philo, "is eating.\n");
	my_usleep(philo, philo->data->time_to_eat);
	pthread_mutex_unlock(philo->my_fork);
	pthread_mutex_unlock(philo->his_fork);
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping.\n");
	my_usleep(philo, philo->data->time_to_sleep);
	pthread_mutex_lock(philo->save);
	pthread_mutex_unlock(philo->save);
	print_status(philo, "is thinking.\n");
}

void	philo_died(t_philo *philo)
{
	pthread_mutex_lock(philo->data->time);
	pthread_mutex_lock(philo->data->death);
	pthread_mutex_lock(philo->save);
	if ((get_time() - philo->last_time_eat) > philo->data->time_to_die
		&& philo->meal_to_eat != 0)
	{
		pthread_mutex_unlock(philo->data->time);
		pthread_mutex_unlock(philo->save);
		pthread_mutex_unlock(philo->data->death);
		print_status(philo, "\e[0;31mis dead ! RIP...\e[0;37m\n");
		pthread_mutex_lock(philo->save);
		philo->still_alive = 0;
		pthread_mutex_unlock(philo->save);
		pthread_mutex_lock(philo->data->death);
		philo->data->someone_died = 1;
		pthread_mutex_unlock(philo->data->death);
	}
	else
	{
		pthread_mutex_unlock(philo->data->time);
		pthread_mutex_unlock(philo->save);
		pthread_mutex_unlock(philo->data->death);
	}
}
