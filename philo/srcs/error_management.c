/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:12:32 by ajearuth          #+#    #+#             */
/*   Updated: 2022/02/01 19:28:39 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;

	while(str)
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
	int i;

	i = 1;
	while (ac == 6 || ac == 5)
	{
		if (ft_isdigit(av[i]) == 0)
			error("arguments must be digit");
		++i;
	}
}
