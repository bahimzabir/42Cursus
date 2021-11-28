/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:46:25 by azabir            #+#    #+#             */
/*   Updated: 2021/11/13 13:49:20 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digcount(int r)
{
	int				j;
	unsigned int	n;

	if (r < 0)
		n = -r;
	else
		n = r;
	j = 0;
	while (n >= 1)
	{
		n = n / 10;
		j++;
	}
	if (r <= 0)
		j++;
	return (j);
}

char	*ft_itoa(int r)
{
	char			*s;
	unsigned int	n;
	int				j;

	j = ft_digcount(r);
	if (r < 0)
		n = -r;
	else
		n = r;
	s = malloc(sizeof(char) * (j + 1));
	if (!s)
		return (NULL);
	s[j] = '\0';
	j--;
	while (j >= 0)
	{
		s[j] = n % 10 + '0';
		n = (n / 10);
		j--;
	}
	if (r < 0)
		s[0] = '-';
	return (s);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(0));
}*/
