/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datacs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snek <snek@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:52:53 by snek              #+#    #+#             */
/*   Updated: 2023/11/28 01:05:04 by snek             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_datac1(t_sec a, char data, int *res)
{
	int		size;
	int		i;

	i = 0;
	size = 1;
	if (a.field[0] > size)
		size = a.field[0];
	if (a.flags[0])
		ft_printer(data, res, &i);
	while (i < size - 1)
		ft_printer(' ', res, &i);
	if (a.flags[0] && i < size)
		ft_printer(' ', res, 0);
	else if (!a.flags[0])
		ft_printer(data, res, 0);
}

static void	ft_pszero(t_sec a, int *res)
{
	int	size;

	size = 6;
	if (a.field[1] && a.field[2] < 6)
		return ;
	if (a.field[0])
	{
		ft_wrstr("(null)", res);
		while (size < a.field[0])
			ft_printer(' ', res, &size);
		return ;
	}
	while (a.field[0] > size)
		ft_printer(' ', res, &size);
	ft_wrstr("(null)", res);
}

static int	ft_strsizer(t_sec a, int size, int *res)
{
	int	totalsize;

	if (size > a.field[2] && a.field[1])
		size = a.field[2];
	if (a.field[0] > size)
		totalsize = a.field[0];
	else
		totalsize = size;
	*res = *res + totalsize;
	return (totalsize);
}

void	ft_datas1(t_sec a, char *data, int *res)
{
	int	size;
	int	totalsize;

	if (!data)
	{
		ft_pszero(a, res);
		return ;
	}
	size = (int)ft_strlen(data);
	totalsize = ft_strsizer(a, size, res);
	if (a.flags[0])
	{
		write(1, data, size);
		while (size++ < totalsize)
			write(1, " ", 1);
	}
	else
	{
		while (size < totalsize--)
			write(1, " ", 1);
		write(1, data, size);
	}
}
