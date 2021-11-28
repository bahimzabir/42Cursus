/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:28:08 by azabir            #+#    #+#             */
/*   Updated: 2021/11/21 19:36:39 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_vprint(char c, void *arg, int *count)
{
	if (c == 'x' || c == 'X')
		ft_putexa_count((unsigned int)arg, count, c);
	else if (c == 's')
		ft_putstr_count((char *)arg, count);
	else if (c == 'c')
		ft_putchar_count((char)arg, count);
	else if (c == 'p')
		ft_putadd_count((unsigned long)arg, count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_count((int)arg, count);
	else if (c == 'u')
		ft_putunbr_count((unsigned int)arg, count);
	else
		return ;
}
