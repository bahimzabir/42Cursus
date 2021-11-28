/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:53:38 by azabir            #+#    #+#             */
/*   Updated: 2021/11/07 15:30:20 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*k;
	char	m;

	i = 0;
	m = c;
	while (s[i] != '\0')
		i++;
	k = (char *)s;
	while (i >= 0)
	{
		if (s[i] == m)
			return (k + i);
		i--;
	}
	return (0);
}
/*
int main()
{
	const char	*s;
	char		c;

	c = ' ';
	s = "Big Fun . Low Fun";
	printf("%s", ft_strrchr(s, c));
}*/
