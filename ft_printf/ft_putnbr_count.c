/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 00:18:19 by azabir            #+#    #+#             */
/*   Updated: 2021/11/27 00:18:22 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr_count(int n, int *count)
{
	int				sign;
	unsigned int	l;
	char			*c;

	c = "0123456789";
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		l = -n;
		write (1, "-", 1);
		*count += 1;
	}
	else
		l = n;
	if (l > 9)
	{
		ft_putnbr_count(l / 10, count);
	}
	*count += 1;
	write(1, &c[l % 10], 1);
}
