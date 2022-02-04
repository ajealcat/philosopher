/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:56:43 by ajearuth          #+#    #+#             */
/*   Updated: 2022/02/04 18:09:39 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	philo_think(t_philo *philo)
{
	print_status(philo, "is thinking.\n");
	pthread_mutex_lock(philo->my_fork);
	print_status(philo, "has taken a fork.\n");
	pthread_mutex_lock(philo->his_fork);
	print_status(philo, "has taken another fork.\n");
}

void	philo_eat(t_philo *philo)
{
	print_status(philo, "is eating.\n");

	pthread_mutex_unlock(philo->my_fork);
	pthread_mutex_unlock(philo->his_fork);
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping.\n");
}

int		is_philo_still_alive(t_philo *philo)
{
	
}
