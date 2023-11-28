/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfuncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:45:26 by snek              #+#    #+#             */
/*   Updated: 2023/11/28 19:43:01 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fieldparser1(char *str, int *cur, t_sec *a)
{
	int		n;

	n = ft_atoi(str + *cur);
	while (str[*cur] <= '9' && str[*cur] >= '0')
		(*cur)++;
	a->field[0] = n;
	if (str[*cur] == '.')
	{
		a->field[1] = 1;
		(*cur)++;
	}
	else
		a->field[1] = 0;
	n = ft_atoi(str + *cur);
	a->field[2] = n;
	while (str[*cur] <= '9' && str[*cur] >= '0')
		(*cur)++;
}

static t_sec	ft_flagparser1(char *str, int *cur)
{
	t_sec	a;
	int		j;

	j = 0;
	while (j < 5)
		a.flags[j++] = 0;
	while (ft_setchr("-0+ #", str[*cur]))
	{
		j = 0;
		while (str[*cur] != "-0+ #"[j])
			j++;
		a.flags[j] = 1;
		(*cur)++;
	}
	ft_fieldparser1(str, cur, &a);
	a.type = str[(*cur)++];
	return (a);
}

static void	ft_args(t_sec a, va_list *ap, int *res)
{
	if (a.type == 'c')
		ft_datac1(a, va_arg(*ap, int), res);
	else if (a.type == 's')
		ft_datas1(a, va_arg(*ap, char *), res);
	else if (a.type == 'p')
		ft_datap1(a, va_arg(*ap, void *), res);
	else if (a.type == 'd' || a.type == 'i')
		ft_datad1(a, va_arg(*ap, int), res);
	else if (a.type == 'u')
		ft_datau1(a, va_arg(*ap, unsigned int), res);
	else if (a.type == 'x' || a.type == 'X')
		ft_datax1(a, va_arg(*ap, unsigned int), res);
	else if (a.type == '%')
		ft_printer('%', res, 0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		cur;
	int		res;
	t_sec	a;

	cur = 0;
	res = 0;
	if (!str)
		return (-1);
	va_start(ap, str);
	while (str[cur])
	{
		if (str[cur] == '%')
		{
			cur++;
			a = ft_flagparser1((char *)str, &cur);
			ft_args(a, &ap, &res);
		}
		else
			ft_printer(str[cur], &cur, &res);
	}
	va_end(ap);
	return (res);
}
