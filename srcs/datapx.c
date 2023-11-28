/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datapx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snek <snek@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:55:44 by snek              #+#    #+#             */
/*   Updated: 2023/11/28 00:59:53 by snek             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hexp(unsigned long int num)
{
	if (num >= 16)
		ft_hexp(num / 16);
	write(1, "0123456789abcdef" + num % 16, 1);
}

static void	ft_hexxp(unsigned long int num)
{
	if (num >= 16)
		ft_hexp(num / 16);
	write(1, "0123456789ABCDEF" + num % 16, 1);
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
	int	size;
	int	totalsize;
	int	ind[3];
	unsigned long int	num;

	num = (unsigned long int)data;
	if (!data)
	{
		ft_wrstr("(nil)", res);
		return ;
	}
	size = ft_flagger(a, ft_hexcount(num), 1, 1);
	totalsize = ft_tsizer(a, size);
	ind[0] = size;
	ind[1] = totalsize;
	ind[2] = 1;
	*res = *res + totalsize;
	ft_nump(a, ind, num, ft_hexp);
}

void	ft_datax1(t_sec a, unsigned int data, int *res)
{
	int	size;
	int	totalsize;
	int	ind[3];
	unsigned long int	num;

	num = (unsigned long int)data;
	if (!data)
	{
		ft_pzero(a, res);
		return ;
	}
	size = ft_flagger(a, ft_hexcount(num), 1, 1);
	totalsize = ft_tsizer(a, size);
	ind[0] = size;
	ind[1] = totalsize;
	ind[2] = 1;
	*res = *res + totalsize;
	if (a.type == 'X')
		ft_nump(a, ind, num, ft_hexxp);
	else
		ft_nump(a, ind, num, ft_hexp);
}
