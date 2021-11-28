/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:53:09 by azabir            #+#    #+#             */
/*   Updated: 2021/11/09 13:01:42 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static long int	ft_putnumber(char *s, int x)
{
	long int	r;

	r = 0;
	while (*s != '\0' && *s >= '0' && *s <= '9')
	{
		r = (r * 10) + (*s - '0');
		if (x < 0 && r > 2147483648)
			return (0);
		else if (r > 2147483647 && x > 0)
			return (-1);
		s++;
	}
	return (r);
}

int	ft_atoi(const char *s)
{
	int	i;
	int	x;

	i = 0;
	x = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	while (s[i] != '\0')
	{
		if ((s[i] == '+' || s[i] == '-')
			&& (s[i + 1] >= '0' && s[i + 1] <= '9'))
		{
			if (s[i] == '-')
				x = -x;
			i++;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			return (x * ft_putnumber((char *)s + i, x));
		}
		else
			break ;
	}
	return (0);
}	
/*
int main()
{
	const char	*c;

	c = "-21474836495";
	printf("%d\n", atoi(c));
	printf("%d\n", ft_atoi(c));
}*/