/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:02:25 by azabir            #+#    #+#             */
/*   Updated: 2021/12/04 02:03:23 by azabir           ###   ########.fr       */
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
	line = malloc(sizeof(char) * (i + 2));
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

int	ft_reading(int fd, char **str)
{
	char		*buf;
	ssize_t		len;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	len = 1;
	while (len != 0 && !ft_nl_check(*str))
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < 0)
		{
			free (buf);
			return (len);
		}
		buf[len] = '\0';
		*str = ft_strjoin(*str, buf);
	}
	free (buf);
	return (len);
}

int	get_next_line(char	**line)
{
	static char	*str;
	int			fd;
	int			r;

	fd = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	r = ft_reading(fd, &str);
	if (!str)
		return (-1);
	*line = ft_line(str);
	str = ft_rm_line(str);
	return (r);
}
