/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:35:32 by azabir            #+#    #+#             */
/*   Updated: 2021/11/09 15:05:32 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

char	*ft_join(char *s1, char *s2)
{
	char	*ptr;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	j = ft_strlen(s1) + ft_strlen (s2);
	ptr = malloc (sizeof(char) * (j + 1));
	if (!ptr)
		return (NULL);
	j = 0;
	while (s1[j])
	{
		ptr[j] = s1[j];
		j++;
	}
	while (*s2)
		ptr[j++] = *s2++;
	ptr [j] = 0;
	return (ptr);
}
