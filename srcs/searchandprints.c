/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchandprints.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snek <snek@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:44:10 by snek              #+#    #+#             */
/*   Updated: 2023/11/28 01:09:06 by snek             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_setchr(char *str, char c)
{
	while (*str)
		if (*(str++) == c)
			return (1);
	return (0);
}

void	ft_incr(int *a, int *b)
{
	(*a)++;
	if (b)
		(*b)++;
}

void	ft_wrstr(char *str, int *res)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	*res = *res + i;
}

void	ft_printer(char c, int *cur, int *res)
{
	write(1, &c, 1);
	ft_incr(cur, res);
}