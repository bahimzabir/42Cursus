/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:44:36 by azabir            #+#    #+#             */
/*   Updated: 2021/11/18 03:36:19 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*k;

	i = 0;
	k = (unsigned char *)s;
	while (i < n)
	{
		k[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int main()
{
	char str[] = "";
	char str2[] = "";
	memset(str, 'y', 1);
	printf("%s\n",str);
	ft_memset(str2, 'y', 1);
	printf("%s\n",str);
}*/
