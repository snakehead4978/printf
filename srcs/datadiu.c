/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datadiu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snek <snek@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:57:24 by snek              #+#    #+#             */
/*   Updated: 2023/11/28 00:57:59 by snek             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_intp(unsigned long int num)
{
	if (num >= 10)
		ft_intp(num / 10);
	write(1, "0123456789" + num % 10, 1);
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
	int	size;
	int	totalsize;
	int	ind[3];
	unsigned long int	num = (unsigned long int)data;

	printf("%d %d %d %d %d %d %d %d\n", a.field[0], a.field[1], a.field[2], a.flags[0], a.flags[1], a.flags[2], a.flags[3], a.flags[4]);
	num = data;
	a.flags[4] = 0;
	ind[2] = 1;
	if (data < 0)
	{
		num = data * -1;
		ind[2] = -1;
	}
	size = ft_flagger(a, ft_intcount(num), 0, ind[2]);
	totalsize = ft_tsizer(a, size);
	ind[0] = size;
	ind[1] = totalsize;
	*res = *res + totalsize;
	ft_nump(a, ind, num, ft_intp);
}

void	ft_datau1(t_sec a, unsigned int data, int *res)
{
	int	size;
	int	totalsize;
	int	ind[3];
	unsigned long int	num;
	
	num = (unsigned long int)data;
	a.flags[4] = 0;
	size = ft_flagger(a, ft_intcount(num), 0, 1);
	totalsize = ft_tsizer(a, size);
	ind[0] = size;
	ind[1] = totalsize;
	ind[2] = 1;
	*res = *res + totalsize;
	ft_nump(a, ind, num, ft_intp);
}