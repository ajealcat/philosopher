/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:37:15 by ajearuth          #+#    #+#             */
/*   Updated: 2022/02/08 12:39:56 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*global_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->stop_when != -1)
	{
		while (philo->data->someone_died == 0 && philo->data->stop_when > 0
			&& philo->meal_to_eat != philo->meal_to_eat - 1)
		{
			if (philo->philo_id % 2 == 0)
				make_pair_philo(philo);
			else
				make_odd_philo(philo);
			--philo->data->stop_when;
		}
	}/*
	if (philo->data->stop_when == -1)
	{
		while (philo->data->someone_died == 0)
		{
			if (philo->philo_id % 2 == 0)
				make_pair_philo(philo);
			else
				make_odd_philo(philo);
			--philo->data->stop_when;
		}
	}*/
	return (philo);
}

void	make_pair_philo(t_philo *philo)
{
	philo_pair(philo);
	philo_eat(philo);
	philo_sleep(philo);
}

void	make_odd_philo(t_philo *philo)
{
	philo_odd(philo);
	philo_eat(philo);
	philo_sleep(philo);
}
