/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:39:08 by azabir            #+#    #+#             */
/*   Updated: 2021/12/21 13:39:14 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>

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
	j = strlen(str) + strlen (buf);
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
	//free (str);
	return (ptr);
}
