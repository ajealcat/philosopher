/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:47:35 by ajearuth          #+#    #+#             */
/*   Updated: 2022/02/01 19:28:40 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_philo
{
	int	nbr_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	stop_when;
}	t_philo;

int		ft_atoi(const char *str);
int		ft_strlen(char *str);
int		error(char *str);
int		args_are_ok(int ac, char **av);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *str, int fd);

t_philo	init_philo(t_philo *philo, char **av);

#endif
