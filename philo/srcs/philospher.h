/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philospher.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:47:35 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/31 16:33:51 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include "libft.h"
# include <stdio.h>
# include <pthread.h>

typedef struct s_philo
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	stop_when;
}	t_philo;

#endif