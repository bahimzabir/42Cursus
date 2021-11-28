/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:46:28 by azabir            #+#    #+#             */
/*   Updated: 2021/11/07 17:03:54 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*k;
	char	m;
	size_t	i;

	m = (unsigned char)c;
	k = (char *)s;
	i = 0;
	while (i < n)
	{
		if (k[i] == m)
			return (k + i);
		else
			i++;
	}
	return (NULL);
}
/*
int main()
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	int	i;
	char		*c;
	
	i = 0;
	c = ft_memchr(s, 2 + 256, 3);
	while (c[i])
	{
		printf("%d", c[i]);
		i++;
	}
}*/