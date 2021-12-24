/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:14:03 by azabir            #+#    #+#             */
/*   Updated: 2021/11/09 11:55:15 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minitalk.h"

void	*ft_calloc(size_t i, size_t s)
{
	char	*p;
	size_t	j;

	p = (char *)malloc(i * s);
	if (!p)
		return (NULL);
	j = 0;
	while (j < i * s)
	{
		p[j] = 0;
		j++;
	}
	return (p);
}
