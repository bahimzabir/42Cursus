/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:14:18 by azabir            #+#    #+#             */
/*   Updated: 2021/11/07 10:02:47 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;	

	s = (char *)src;
	d = (char *)dst;
	if (!d && !s)
		return (NULL);
	i = len;
	if (d > s)
		while (i-- > 0)
			d[i] = s[i];
	else
	{
		i = 0;
		while (i < len && dst != src)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}
/*
int    main()
{
    char c[] = "Khit Byad";
	ft_memmove(c + 2, c , 7);
    printf("%s",c);
}*/
