/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snek <snek@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:06:34 by snek              #+#    #+#             */
/*   Updated: 2023/11/28 00:26:48 by snek             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	long		sign;
	long		res;

	sign = 1;
	i = 0;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] <= 13 && nptr[i] >= 9))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		res = res * 10 + nptr[i++] - '0';
	return ((int)(res * sign));
};

size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (*str++)
		a++;
	return (a);
};

int	ft_setchr(char *str, char c)
{
	while (*str)
		if (*(str++) == c)
			return (1);
	return (0);
};

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

void	ft_fieldparser1(char *str, int *cur, int *res, t_sec *a)
{
	int		n;
	char	*tmp;
	size_t	size;

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

t_sec	ft_flagparser1(char *str, int *cur, int *res)
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
	ft_fieldparser1(str, cur, res, &a);
	a.type = str[(*cur)++];
	return (a);
}

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

void	ft_args(t_sec a, va_list *ap, int *res)
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
		return (0);
	va_start(ap, str);
	while (str[cur])
	{
		if (str[cur] == '%')
		{
			cur++;
			a = ft_flagparser1((char *)str, &cur, &res);
			ft_args(a, &ap, &res);
		}
		else
			ft_printer(str[cur], &cur, &res);
	}
	va_end(ap);
	return (res);
}
