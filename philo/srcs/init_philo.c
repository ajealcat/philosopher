/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:58:09 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/31 16:33:49 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/* Your(s) program(s) should take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/

t_philo	init_philo(t_philo philo, char **av)
{
	philo.time_to_die = ft_atoi(av[2]);
	philo.time_to_eat = ft_atoi(av[3]);
	philo.time_to_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		philo.stop_when = ft_atoi(av[5]);
	else
		philo.stop_when = NULL;
}
