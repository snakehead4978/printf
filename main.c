/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snek <snek@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:02:02 by snek              #+#    #+#             */
/*   Updated: 2023/11/28 00:42:52 by snek             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
	int a, b;

	a = ft_printf("%s\n", "");
	b = printf("%s\n", "");
	printf("%d %d TESTER\n", a , b);
	a = ft_printf(" %s\n", "");
	b = printf(" %s\n", "");
	printf("%d %d TESTER\n", a , b);
	a = ft_printf("%s \n", "");
	b = printf("%s \n", "");
	printf("%d %d TESTER\n", a , b);
	a = ft_printf(" %s \n", "");
	b = printf(" %s \n", "");
	printf("%d %d TESTER\n", a , b);
	a = ft_printf(" %s \n", "-");
	b = printf(" %s \n", "-");
	printf("%d %d TESTER\n", a , b);
	a = ft_printf(" %s %s \n", "", "-");
	b = printf(" %s %s \n", "", "-");
	printf("%d %d TESTER\n", a , b);
	a = ft_printf(" %s %s \n", " - ", "");
	b = printf(" %s %s \n", " - ", "");
	printf("%d %d TESTER\n", a , b);
	a = ft_printf(" %s %s %s %s %s\n", " - ", "", "4", "", s2);
	b = printf(" %s %s %s %s %s\n", " - ", "", "4", "", s2);
	printf("%d %d TESTER\n", a , b);
	a = ft_printf(" %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
	b = printf(" %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
	printf("%d %d TESTER\n", a , b);
	a = ft_printf(" NULL %s NULL \n", NULL);
	b = printf(" NULL %s NULL \n", NULL);
	printf("%d %d TESTER\n", a , b);
}
