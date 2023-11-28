/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numsizes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:38:17 by jla-chon          #+#    #+#             */
/*   Updated: 2023/11/28 19:22:21 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_tsizer(t_sec a, int *size, int actualsize, int sign)
{
	*size = actualsize;
	if (actualsize < a.field[2] && a.field[1])
		*size = a.field[2];
	if (a.flags[4] || a.type == 'p')
		*size += 2;
	if (a.flags[2] || a.flags[3] || sign == -1)
		(*size)++;
	if (a.field[0] > *size)
		return (a.field[0]);
	return (*size);
}

void	ft_tabler(int table[4], int size, int totalsize, int actualsize)
{
	table[0] = size;
	table[1] = totalsize;
	table[3] = actualsize;
}
