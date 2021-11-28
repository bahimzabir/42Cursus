/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:11:43 by azabir            #+#    #+#             */
/*   Updated: 2021/11/27 17:12:28 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putadd_count(unsigned long arg, int *count)
{
	char	*c;

	c = "0123456789abcdef";
	if (arg > 15)
		ft_putadd_count((arg / 16), count);
	*count += 1;
	if (arg <= 15)
	{
		write(1, "0x", 2);
		*count += 2;
	}
	write (1, &c[arg % 16], 1);
}
