/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:22:21 by azabir            #+#    #+#             */
/*   Updated: 2021/11/09 14:35:08 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*p;

	if (!s)
		return (NULL);
	j = (size_t)ft_strlen(s);
	if (len > j)
		len = j;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (i < len && j > start)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
/*
int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "tripouille";
	s2 = ft_substr(s1, 100, 1);
	printf("%s", s2);
	free(s2);
}*/