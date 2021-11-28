/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                           :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:39:12 by azabir            #+#    #+#             */
/*   Updated: 2021/11/06 18:58:33 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dst;
	s = src;
	if (!s && !d)
		return (NULL);
	i = 0;
	while (i < n && dst != src)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

/*
int    main()
{
    //char c[] = "";
    //char d[0];
  printf("%s", ft_memcpy("hello", "hello", 5));
   // printf("%s", memcpy("hello", "hello", 5));
}*/
