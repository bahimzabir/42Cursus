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

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	char	*p;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1 [0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	j = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (j + 1));
	if (!p)
		return (NULL);
	j = 0;
	while (s1[j])
	{
		p[j] = s1[j];
		j++;
	}
	while (*s2)
		p[j++] = *s2++;
	p[j] = '\0';
	free (s1);
	return (p);
}

char	*ft_new_line(char *s1)
{
	char	*s2;
	int		i;

	if (!*s1)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
		if (s2[i - 1] == '\n')
			break ;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_newstr(char *str)
{
	int		i;
	int		j;
	char	*nstr;

	i = 0;
	while (str[i] != '\n')
	{
		if (!str[i])
		{
			free(str);
			return (NULL);
		}
		i++;
	}
	nstr = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	j = 0;
	i++;
	while (str[i + j])
	{
		nstr[j] = str[i + j];
		j++;
	}
	nstr[j] = '\0';
	free(str);
	return (nstr);
}
