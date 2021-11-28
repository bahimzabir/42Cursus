/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:06:46 by azabir            #+#    #+#             */
/*   Updated: 2021/11/13 22:17:44 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

/*
static char	ft_test(unsigned int i, char c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else if (c >= 97 && c <= 122)
		return (c - 32);
	else if (c == 32)
		return (c);
	return (i + 48);	
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*p;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	p = malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*
int	main(void)
{
	printf("%s\n",ft_strmapi("KHItBYAD DYALI",ft_test));
	return (0);
}
*/