/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 20:26:29 by azabir            #+#    #+#             */
/*   Updated: 2021/11/13 23:50:05 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static void	ft_test(unsigned int i, char *c)
{
	i = 0;
	if (*c >= 65 && *c <= 90)
		*c = *c + 32;
	else if (*c >= 97 && *c <= 122)
		*c = *c - 32;
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int		i;
	unsigned int		j;

	if (s)
	{
		i = 0;
		j = 0;
		while (s[i])
			i++;
		while (j < i)
		{
			f(j, s + j);
			j++;
		}
	}
}
/*
int	main(void)
{	
	char	s[] = "kadiw lbni makada ??";
	ft_striteri(s, ft_test);
	printf("%s\n", s);
	return (0);
}*/
