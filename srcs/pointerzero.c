/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointerzero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:56:23 by snek              #+#    #+#             */
/*   Updated: 2023/11/28 18:29:53 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ppzero(t_sec a, int *res)
{
	int	size;

	size = 5;
	if (a.field[1] && a.field[2] < 5)
	{
		while (a.field[0]--)
			ft_printer(' ', res, 0);
		return ;
	}
	if (a.flags[0])
	{
		ft_wrstr("(nil)", res);
		while (size < a.field[0])
			ft_printer(' ', res, &size);
		return ;
	}
	while (a.field[0] > size)
		ft_printer(' ', res, &size);
	ft_wrstr("(nil)", res);
}
