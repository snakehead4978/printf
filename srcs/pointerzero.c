/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intprint_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snek <snek@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:56:23 by snek              #+#    #+#             */
/*   Updated: 2023/11/28 00:59:29 by snek             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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