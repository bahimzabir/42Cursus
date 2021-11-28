/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:35:32 by azabir            #+#    #+#             */
/*   Updated: 2021/11/09 15:05:32 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_joinlen(char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		j++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		j;
	char	*p;

	if (!s1 || !s2)
		return (0);
	j = ft_joinlen(s1, s2);
	p = (char *)malloc(sizeof(char) * (j + 1));
	if (!p)
		return (NULL);
	j = 0;
	while (*s1)
	{
		p[j] = *s1;
		j++;
		s1++;
	}
	while (*s2)
	{
		p[j] = *s2;
		j++;
		s2++;
	}
	p[j] = '\0';
	return (p);
}
/*
int	main(void)
{
	char	*s1;
	char	*s2;
	char	*s3;

	s1 = "ANA";
	s2 = " KHDAMA";
	s3 = ft_strjoin(s1, s2);
	printf("%s", s3);
	free(s3);
}*/
