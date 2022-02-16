/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:12:32 by ajearuth          #+#    #+#             */
/*   Updated: 2022/02/16 14:24:59 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (!(str == NULL))
		write(fd, str, ft_strlen(str));
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	error(char *str)
{
	ft_putstr_fd(str, 2);
	return (-1);
}

int	args_are_ok(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	if (ac != 5 && ac != 6)
		return (error("Error : Invalid number of arguments\n"));
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
				return (error("Error : Invalid arguments\n"));
			if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < 0
				|| ft_strlen(av[i]) > 11)
				return (error("Error : Invalid arguments\n"));
			++j;
		}
		++i;
	}
	return (1);
}
