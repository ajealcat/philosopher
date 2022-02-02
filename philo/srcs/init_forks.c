/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:32:09 by ajearuth          #+#    #+#             */
/*   Updated: 2022/02/02 16:03:05 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

pthread_mutex_t	*create_mutex(void)
{
	pthread_mutex_t	*mutex;

	mutex = malloc(sizeof(pthread_mutex_t));
	if (mutex == NULL)
	{
		ft_putstr_fd("Error: mutex malloc failed\n", 2);
		return (NULL);
	}
	if (pthread_mutex_init(mutex, NULL) != 0)
	{
		free(mutex);
		ft_putstr_fd("Error: philos mutex initialisation failed\n", 2);
		return (NULL);
	}
	return (mutex);
}

int init_mutex(t_philo *philo)
{
	philo->my_fork = create_mutex();
	if (philo->my_fork == NULL)
		return (-1);
	philo->save = create_mutex();
	if (philo->save == NULL)
	{
		free(philo->my_fork);
		return (-1);
	}
	return (1);
}
