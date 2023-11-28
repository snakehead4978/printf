/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:02:02 by snek              #+#    #+#             */
/*   Updated: 2023/11/28 19:31:15 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define LONG_MAX  __LONG_MAX__
#define LONG_MIN  (-__LONG_MAX__ -1L)

int main(void)
{
	int a, b;

	a = ft_printf("%7i", -14);
	b = printf("%7i", -14);
	write(1, "\n", 1);
	printf("\n%d %d TESTER\n", a , b);
	a = ft_printf("%05i", 43);
	b = printf("%05i", 43);
	write(1, "\n", 1);
	printf("\n%d %d TESTER\n", a , b);
	a = ft_printf("%010.5i", -216);
	b = printf("%010.5i", -216);
	printf("\n%d %d TESTER\n", a , b);
	a = ft_printf("a%3.0ia", 0);
	b = printf("a%3.0ia", 0);
	write(1, "\n", 1);
	printf("\n%d %d TESTER\n", a , b);
	a = ft_printf(" %p %p ", -2147483648, 2147483647);
	b = printf(" %p %p ", -2147483648, 2147483647);
	write(1, "\n", 1);
	printf("\n%d %d TESTER\n", a , b);
	a = ft_printf("%X", 4294967295u);
	b = printf("%X", 4294967295u);
	write(1, "\n", 1);
	printf("\n%d %d TESTER\n", a , b);
	a = ft_printf(" %-9p %-10p ", LONG_MIN, LONG_MAX);
	b = printf(" %-9p %-10p ", LONG_MIN, LONG_MAX);
	write(1, "\n", 1);
	printf("\n%d %d TESTER\n", a , b);
}
