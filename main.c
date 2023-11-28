/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:02:02 by snek              #+#    #+#             */
/*   Updated: 2023/11/28 18:26:59 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	a = ft_printf("a%.3xa", 0);
	b = printf("a%.3xa", 0);
	write(1, "\n", 1);
	printf("\n%d %d TESTER\n", a , b);
	a = ft_printf("%X", 4294967295u);
	b = printf("%X", 4294967295u);
	write(1, "\n", 1);
	printf("\n%d %d TESTER\n", a , b);
	a = ft_printf("%15p\n", NULL);
	b = printf("%15p\n", NULL);
	write(1, "\n", 1);
	printf("\n%d %d TESTER\n", a , b);
}
