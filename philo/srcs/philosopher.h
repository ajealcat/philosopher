/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:47:35 by ajearuth          #+#    #+#             */
/*   Updated: 2022/02/08 11:40:50 by ajearuth         ###   ########.fr       */
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
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				stop_when;
	int				someone_died;
	long int		departure_time;
	pthread_mutex_t	*time;
	pthread_mutex_t	*write;
	struct s_philo	*philo;
}	t_data;

typedef struct s_philo
{
	int				philo_id;
	int				still_alive;
	int				meal_to_eat;
	long int		last_time_eat;
	pthread_t		thread_id;
	pthread_mutex_t	*my_fork;
	pthread_mutex_t	*his_fork;
	pthread_mutex_t	*save;
	t_data			*data;
}	t_philo;

int					ft_atoi(const char *str);
int					ft_strlen(char *str);
int					error(char *str);
int					args_are_ok(int ac, char **av);
int					ft_isdigit(int c);
int					init_mutex(t_philo *philo);
int					create_threads(t_data *data);
long int			get_time(void);
void				find_his_fork(t_philo *philo);
void				ft_putstr_fd(char *str, int fd);
void				philo_pair(t_philo *philo);
void				philo_odd(t_philo *philo);
void				philo_eat(t_philo *philo);
void				philo_sleep(t_philo *philo);
void				*global_philo(void *philo);
void				my_usleep(t_philo *philo, long int timing);
void				print_status(t_philo *philo, char *str);
void				make_pair_philo(t_philo *philo);
void				make_odd_philo(t_philo *philo);
pthread_mutex_t		*create_mutex(void);

t_data				init_data(t_data *data, char **av);

#endif
