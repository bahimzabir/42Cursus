/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:48:33 by azabir            #+#    #+#             */
/*   Updated: 2021/11/07 17:10:43 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*k;
	char	m;

	i = 0;
	m = c;
	k = (char *)s;
	while (*s)
	{
		if (*s == m)
			return (k + i);
		else
			i++;
		s++;
	}
	if (*s == c)
		return (k + i);
	return (0);
}
/*
int main()
{
	const char	*s;
	char		c;
	
	c = 'l';
	s = "Big Fun . Low Fun";
	printf("%s", strchr(s, c));
}*/
