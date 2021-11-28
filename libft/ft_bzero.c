/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:24:38 by azabir            #+#    #+#             */
/*   Updated: 2021/11/06 16:35:07 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void	*s, size_t	n)
{
	size_t	i;
	char	*k;

	k = s;
	i = 0;
	while (i < n)
	{
		k[i] = '\0';
		i++;
	}
}
/*
int	main()
{	
	int i;
	int j;

	i = 0;
	j = 0;
	char c[] = "Khit Byad";
	while (c[i])
		i++;
	bzero(c , 3);
	while (j++ < i)
	printf("%c",c[j]);
}
*/