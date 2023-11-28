/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:51:44 by snek              #+#    #+#             */
/*   Updated: 2023/11/28 19:34:43 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_numflagprint(t_sec a, unsigned long int num, int sign, int *i)
{
	if (a.flags[2])
	{
		if (sign == 1)
			ft_printer('+', i, 0);
	}
	else if (a.flags[3] && sign != -1)
		ft_printer(' ', i, 0);
	if (sign == -1)
		ft_printer('-', i, 0);
	if (((a.flags[4] && a.type == 'x') || a.type == 'p') && num)
		ft_wrstr("0x", i);
	else if (a.flags[4] && a.type == 'X' && num)
		ft_wrstr("0X", i);
}

static void	ft_numpall(t_sec a, int ind[4], unsigned long int num,
		void (*f)(unsigned long int, int))
{
	while (ind[1] > ind[0])
		ft_printer(' ', &(ind[0]), &(ind[3]));
	ft_numflagprint(a, num, ind[2], &(ind[3]));
	if (a.field[1])
		while (ind[3] < ind[0])
			ft_printer('0', &(ind[3]), 0);
	else
		while (ind[3] < ind[0])
			ft_printer(' ', &(ind[3]), 0);
	if (!num && a.field[1] && !a.field[2])
		f(num, 0);
	else
		f(num, 1);
}

static void	ft_numpleft(t_sec a, int ind[4], unsigned long int num,
		void (*f)(unsigned long int, int))
{
	ft_numflagprint(a, num, ind[2], &(ind[3]));
	while (ind[3] < ind[0])
		ft_printer('0', &(ind[3]), 0);
	if (!num && a.field[1] && !a.field[2])
		f(num, 0);
	else
		f(num, 1);
	while (ind[0]++ < ind[1])
		write(1, " ", 1);
}

static void	ft_numpzero(t_sec a, int ind[4], unsigned long int num,
		void (*f)(unsigned long int, int))
{
	while (ind[0] < ind[1] && a.field[1])
		ft_printer(' ', &(ind[3]), &(ind[0]));
	ft_numflagprint(a, num, ind[2], &(ind[3]));
	while (ind[0] > ind[3] || (ind[3] < ind[1] && !a.field[1]))
		ft_printer('0', &(ind[3]), 0);
	if (!num && a.field[1] && !a.field[2])
		f(num, 0);
	else
		f(num, 1);
}

void	ft_nump(t_sec a, int ind[4], unsigned long int num,
		void (*f)(unsigned long int, int))
{
	if (a.flags[0])
		ft_numpleft(a, ind, num, f);
	else if (a.flags[1])
		ft_numpzero(a, ind, num, f);
	else
		ft_numpall(a, ind, num, f);
}
