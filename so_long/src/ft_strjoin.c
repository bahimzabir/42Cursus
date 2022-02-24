/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 08:50:53 by azabir            #+#    #+#             */
/*   Updated: 2022/02/24 08:50:57 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

char	*ft_strjoin(char *str, char *buf)
{
	char	*ptr;
	size_t	j;

	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = 0;
	}
	if (!str || !buf)
		return (NULL);
	j = ft_strlen(str) + ft_strlen (buf);
	ptr = malloc (sizeof(char) * (j + 1));
	if (!ptr)
		return (NULL);
	j = 0;
	while (str[j])
	{
		ptr[j] = str[j];
		j++;
	}
	while (*buf)
		ptr[j++] = *buf++;
	ptr [j] = 0;
	free (str);
	return (ptr);
}
