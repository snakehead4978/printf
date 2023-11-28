/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snek <snek@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:06:34 by snek              #+#    #+#             */
/*   Updated: 2023/11/28 00:52:26 by snek             ###   ########.fr       */
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

void	ft_pszero(t_sec a, int *res)
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
	if (size > a.field[2] && a.field[1])
		size = a.field[2];
	if (a.field[0] > size)
		totalsize = a.field[0];
	else
		totalsize = size;
	*res = *res + totalsize;
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

void	ft_pzero(t_sec a, int *res)
{
	int	size;
	int	totalsize;

	size = 0;
	if (a.flags[0])
	{
		if (a.flags[2])
			ft_printer('+', res, &size);
		else if (a.flags[3])
			ft_printer(' ', res, &size);
		ft_printer('0', res, &size);
		ft_printer(' ', res, &size);
		while (size < a.field[0])
			ft_printer(' ', res, &size);
		return ;
	}
	size = ft_flagger(a, 1, 0, 1);
	while (size < a.field[0])
		ft_printer(' ', res, &size);
	if (a.flags[2])
		ft_printer('+', res, &size);
	else if (a.flags[3])
		ft_printer(' ', res, &size);
	ft_printer('0', res, &size);
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


