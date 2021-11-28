/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:58:30 by azabir            #+#    #+#             */
/*   Updated: 2021/11/26 18:16:33 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

void	ft_putstr_count(char *c, int *count);

void	ft_vprint(char c, void *arg, int *count);

int		ft_printf(const char *s, ...);

void	ft_putchar_count(char c, int *count);

void	ft_putnbr_count(int n, int *count);

void	ft_putexa_count(unsigned int n, int *count, char c);

void	ft_putadd_count(unsigned long arg, int *count);

void	ft_putunbr_count(unsigned int n, int *count);

#endif
