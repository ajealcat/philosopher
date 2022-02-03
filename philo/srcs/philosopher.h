/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:47:35 by ajearuth          #+#    #+#             */
/*   Updated: 2022/02/03 15:11:22 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/time.h>
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_data
{
	int	nbr_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	stop_when;
	pthread_t	each_philo;
	struct s_philo	*philo;
}	t_data;

typedef struct s_philo
{
	int	philo_id;
	int	fork_nbr;
	int	still_alive;
	pthread_mutex_t	*my_fork;
	pthread_mutex_t	*his_fork;
	pthread_mutex_t	*save;
	int	meal_to_eat;
	t_data	*data;
} t_philo;

int		ft_atoi(const char *str);
int		ft_strlen(char *str);
int		error(char *str);
int		args_are_ok(int ac, char **av);
int		ft_isdigit(int c);
int		init_mutex(t_philo *philo);
void	ft_putstr_fd(char *str, int fd);

pthread_mutex_t	*create_mutex(void);

t_data	init_data(t_data *data, char **av);

#endif
