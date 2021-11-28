/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:24:28 by azabir            #+#    #+#             */
/*   Updated: 2021/11/18 17:49:53 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkif(const char *this, const char	*inthis, size_t e, size_t l)
{
	size_t	j;

	j = 0;
	while (this[j] != '\0')
	{
		if (this[j] == inthis[e] && e < l)
		{
			j++;
			e++;
		}
		else
			return (0);
	}
	return (1);
}

char	*ft_strnstr(const char *h, const char *n, size_t l)
{
	size_t	i;
	size_t	e;

	i = 0;
	if (!n[i])
		return ((char *)h);
	while (i < l && h[i])
	{
		e = i;
		if (ft_checkif(n, h, e, l) == 1)
			return ((char *)h + i);
		i++;
	}
	return (NULL);
}
/*
int	main()
{
		const char *largestring = "aaabcabcd";
		const char *smallstring = "aabc";
		printf("%s", ft_strnstr(largestring, smallstring, -1));
}
*/
