/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:58:58 by azabir            #+#    #+#             */
/*   Updated: 2021/11/21 18:59:30 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		count;

	count = 0;
	va_start(arg, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '%')
			{
				write(1, "%%", 1);
				count++;
			}
			else
				ft_vprint(*s, va_arg(arg, char *), &count);
		}
		else
			ft_putchar_count(*s, &count);
		s++;
	}
	va_end(arg);
	return (count);
}
