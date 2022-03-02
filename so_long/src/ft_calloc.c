/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:11:05 by azabir            #+#    #+#             */
/*   Updated: 2022/03/01 17:11:10 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

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
