/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datadiu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:57:24 by snek              #+#    #+#             */
/*   Updated: 2023/11/28 18:26:35 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_intp(unsigned long int num, int i)
{
	if (!num && !i)
	{
		write(1, " ", 1);
		return ;
	}
	if (num >= 10)
		ft_intp(num / 10, i + 1);
	write(1, &("0123456789"[num % 10]), 1);
}

static int	ft_intcount(unsigned long int num)
{
	int	i;

	i = 0;
	while (num >= 10)
	{
		i++;
		num /= 10;
	}
	return (i + 1);
}

void	ft_datad1(t_sec a, int data, int *res)
{
	int					size;
	int					totalsize;
	int					actualsize;
	int					ind[4];
	unsigned long int	num;

	num = (unsigned long int)data;
	a.flags[4] = 0;
	ind[2] = 1;
	if (data < 0)
	{
		num = (unsigned long int)data * -1;
		ind[2] = -1;
	}
	actualsize = ft_intcount(num);
	size = 0;
	totalsize = ft_tsizer(a, &size, actualsize, ind[2]);
	ind[0] = size;
	ind[1] = totalsize;
	ind[3] = actualsize;
	if (!data && !a.field[0] && a.field[1] && !a.field[2])
		return ;
	*res = *res + totalsize;
	ft_nump(a, ind, num, ft_intp);
}

void	ft_datau1(t_sec a, unsigned int data, int *res)
{
	int					size;
	int					totalsize;
	int					actualsize;
	int					ind[4];
	unsigned long int	num;

	num = (unsigned long int)data;
	a.flags[4] = 0;
	size = 0;
	actualsize = ft_intcount(num);
	size = 0;
	totalsize = ft_tsizer(a, &size, actualsize, 1);
	ind[0] = size;
	ind[1] = totalsize;
	ind[2] = 1;
	ind[3] = actualsize;
	if (!data && !a.field[0] && a.field[1] && !a.field[2])
		return ;
	*res = *res + totalsize;
	ft_nump(a, ind, num, ft_intp);
}
