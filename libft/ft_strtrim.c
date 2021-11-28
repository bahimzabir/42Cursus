/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:06:30 by azabir            #+#    #+#             */
/*   Updated: 2021/11/09 19:34:02 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		else
			s++;
	}
	return (0);
}

static int	ft_checkb(char const *s, char const	*set)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_check(set, s[i]) == 1)
			i++;
		else
			break ;
	}
	return (i);
}

static int	ft_checke(char const *s, char const *set)
{
	int	j;

	j = ft_strlen(s) - 1;
	while (j > 0)
	{
		if (ft_check(set, s[j]))
			j--;
		else
			break ;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*p;

	if (!s1)
		return (0);
	i = ft_checkb(s1, set);
	j = ft_checke(s1, set);
	if (j < i)
		j = i - 1;
	p = (char *)malloc(sizeof(char) * (j - i) + 2);
	if (!p)
		return (NULL);
	k = 0;
	if (j == i)
		p[k++] = s1[i];
	else
		while (i <= j)
			p[k++] = s1[i++];
	p[k] = '\0';
	return (p);
}
/*
int	main(void)
{
	char	*s1;
	char	*set;
	char	*trim;

	s1 = "   f     ";
	set = " ";
	trim = ft_strtrim(s1, set);
	printf("%s\n", trim);
	free(trim);
}*/