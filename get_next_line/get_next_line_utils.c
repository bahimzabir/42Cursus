/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:08:00 by azabir            #+#    #+#             */
/*   Updated: 2021/11/27 23:08:49 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	s2 = (char *)malloc(i * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}