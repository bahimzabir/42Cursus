/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putexa_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 03:59:25 by azabir            #+#    #+#             */
/*   Updated: 2021/11/27 03:59:27 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putexa_count(unsigned int n, int *count, char c)
{
	char			*c1;
	char			*c2;

	c1 = "0123456789abcdef";
	c2 = "0123456789ABCDEF";
	if (n > 15)
		ft_putexa_count(n / 16, count, c);
	*count += 1;
	if (c == 'x')
		write(1, &c1[n % 16], 1);
	else if (c == 'X')
		write(1, &c2[n % 16], 1);
}
