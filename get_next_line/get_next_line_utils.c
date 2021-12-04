/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:08:00 by azabir            #+#    #+#             */
/*   Updated: 2021/11/27 23:08:49 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_nl_check(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!*str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i])
	{
		line[i] = str[i];
		i++;
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = 0;
	return (line);
}

char	*ft_rm_line(char *str)
{
	char	*nstr;
	int		i;
	int		l;

	l = 0;
	while (str[l] && str[l] != '\n')
		l++;
	if (!str[l])
	{
		free(str);
		return (NULL);
	}
	nstr = malloc(sizeof(char) * (ft_strlen(str) - l + 1));
	if (!nstr)
		return (NULL);
	i = 0;
	l++;
	while (str[l + i])
	{
		nstr[i] = str [l + i];
		i++;
	}
	nstr[i] = 0;
	free (str);
	return (nstr);
}
