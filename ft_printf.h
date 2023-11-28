/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snek <snek@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:41:30 by snek              #+#    #+#             */
/*   Updated: 2023/11/28 01:09:00 by snek             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_sec
{
	int		flags[5];
	int		field[3];
	char	type;
}			t_sec;


int	ft_printf(const char *str, ...);
void	ft_datac1(t_sec a, char data, int *res);
void	ft_datas1(t_sec a, char *data, int *res);
void	ft_datad1(t_sec a, int data, int *res);
void	ft_datau1(t_sec a, unsigned int data, int *res);
void	ft_datap1(t_sec a, void *data, int *res);
void	ft_datax1(t_sec a, unsigned int data, int *res);
int	ft_atoi(const char *nptr);
size_t	ft_strlen(const char *str);
void	ft_pzero(t_sec a, int *res);
void	ft_numflagprint(t_sec a, int pointer, int sign);
int	ft_tsizer(t_sec a, int size);
int	ft_flagger(t_sec a, int size, int pointer, int sign);
void	ft_nump(t_sec a, int ind[3], unsigned long int num, void (*f)(unsigned long int));
int	ft_setchr(char *str, char c);
void	ft_incr(int *a, int *b);
void	ft_wrstr(char *str, int *res);
void	ft_printer(char c, int *cur, int *res);


#endif