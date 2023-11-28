/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:41:30 by snek              #+#    #+#             */
/*   Updated: 2023/11/28 19:39:10 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_sec
{
	int		flags[5];
	int		field[3];
	char	type;
}			t_sec;

int			ft_printf(const char *str, ...);
void		ft_datac1(t_sec a, char data, int *res);
void		ft_datas1(t_sec a, char *data, int *res);
void		ft_datad1(t_sec a, int data, int *res);
void		ft_datau1(t_sec a, unsigned int data, int *res);
void		ft_datap1(t_sec a, void *data, int *res);
void		ft_datax1(t_sec a, unsigned int data, int *res);
int			ft_atoi(const char *nptr);
size_t		ft_strlen(const char *str);
void		ft_ppzero(t_sec a, int *res);
int			ft_tsizer(t_sec a, int *size, int actualsize, int sign);
void		ft_nump(t_sec a, int ind[4], unsigned long int num,
				void (*f)(unsigned long int, int));
int			ft_setchr(char *str, char c);
void		ft_incr(int *a, int *b);
void		ft_wrstr(char *str, int *res);
void		ft_printer(char c, int *cur, int *res);
void		ft_tabler(int table[4], int size, int totalsize, int actualsize);

#endif