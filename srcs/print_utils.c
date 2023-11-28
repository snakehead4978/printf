/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snek <snek@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:51:44 by snek              #+#    #+#             */
/*   Updated: 2023/11/28 00:52:16 by snek             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_numflagprint(t_sec a, int pointer, int sign)
{
	if (a.flags[2])
	{
		if (sign == 1)
			write(1, "+", 1);
	}
	else if (a.flags[3] && sign != -1)
		write(1, " ", 1);
	if (sign == -1)
		write(1, "-", 1);
	if ((a.flags[4] && a.type == 'x') || pointer)
		write(1, "0x", 2);
	else if (a.flags[4] && a.type == 'X')
		write(1, "0X", 2);
}

int	ft_tsizer(t_sec a, int size)
{
	if (a.field[0] > size)
		return (a.field[0]);
	return (size);
}

int	ft_flagger(t_sec a, int size, int pointer, int sign)
{
	if (a.flags[4] || pointer)
		size += 2;
	if (a.flags[2] || a.flags[3] || sign == -1)
		size++;
	return (size);
}

void	ft_nump(t_sec a, int ind[3], unsigned long int num, void (*f)(unsigned long int))
{
	if (a.flags[0])
	{
		ft_numflagprint(a, (a.type == 'p'), ind[2]);
		f(num);
		while (ind[0]++ < ind[1])
			write(1, " ", 1);
	}
	else if (a.flags[1])
	{
		ft_numflagprint(a, (a.type == 'p'), ind[2]);
		while (ind[1] - ind[0]++)
			write(1, "0", 1);
		f(num);
	}
	else
	{
		while (ind[1] - ind[0]++)
			write(1, " ", 1);
		ft_numflagprint(a, (a.type == 'p'), ind[2]);
		f(num);
	}
}
