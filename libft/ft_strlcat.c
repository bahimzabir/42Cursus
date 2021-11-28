/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:58:22 by azabir            #+#    #+#             */
/*   Updated: 2021/11/18 21:19:42 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t ds)
{
	size_t	i;
	size_t	j;
	size_t	l;
	char	*k;

	k = (char *)src;
	l = ft_strlen(dst);
	i = l + ft_strlen(k);
	j = 0;
	if (ds != 0 && l < ds - 1)
	{
		while (l + j < ds - 1 && src[j])
		{
			dst[l + j] = src[j];
			j++;
		}
	dst[l + j] = '\0';
	}
	if (l > ds)
		i = i - (l - ds);
	return (i);
}
/*
#include<string.h>
int	main()
{
//	char	dst[14] = "OFF";
	char	src[] = "iAlR44";
	printf("%lu\n",strlcat(NULL, src, 0));
//	printf("%s\n", dst);
}
*/
