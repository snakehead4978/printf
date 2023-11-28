/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datapx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:55:44 by snek              #+#    #+#             */
/*   Updated: 2023/11/28 19:32:13 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hexp(unsigned long int num, int i)
{
	if (!num && !i)
	{
		write(1, " ", 1);
		return ;
	}
	if (num >= 16)
		ft_hexp(num / 16, i + 1);
	write(1, &("0123456789abcdef"[num % 16]), 1);
}

static void	ft_hexxp(unsigned long int num, int i)
{
	if (!num && !i)
	{
		write(1, " ", 1);
		return ;
	}
	if (num >= 16)
		ft_hexxp(num / 16, i + 1);
	write(1, &("0123456789ABCDEF"[num % 16]), 1);
}

static int	ft_hexcount(unsigned long int num)
{
	int	i;

	i = 0;
	while (num >= 16)
	{
		i++;
		num /= 16;
	}
	return (i + 1);
}

void	ft_datap1(t_sec a, void *data, int *res)
{
	int					size;
	int					totalsize;
	int					actualsize;
	int					ind[4];
	unsigned long int	num;

	num = (unsigned long int)data;
	if (!data)
	{
		ft_ppzero(a, res);
		return ;
	}
	actualsize = ft_hexcount(num);
	size = 0;
	totalsize = ft_tsizer(a, &size, actualsize, 1);
	ft_tabler(ind, size, totalsize, actualsize);
	ind[2] = 1;
	*res = *res + totalsize;
	ft_nump(a, ind, num, ft_hexp);
}

void	ft_datax1(t_sec a, unsigned int data, int *res)
{
	int					size;
	int					totalsize;
	int					actualsize;
	int					ind[4];
	unsigned long int	num;

	num = (unsigned long int)data;
	actualsize = ft_hexcount(num);
	size = 0;
	totalsize = ft_tsizer(a, &size, actualsize, 1);
	if (!data && a.flags[4])
	{
		totalsize -= 2;
		size -= 2;
	}
	ft_tabler(ind, size, totalsize, actualsize);
	ind[2] = 1;
	if (!data && !a.field[0] && a.field[1] && !a.field[2])
		return ;
	*res = *res + totalsize;
	if (a.type == 'X')
		ft_nump(a, ind, num, ft_hexxp);
	else
		ft_nump(a, ind, num, ft_hexp);
}
