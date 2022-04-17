/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_nl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:51:09 by azabir            #+#    #+#             */
/*   Updated: 2022/04/16 20:51:14 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

char	*ft_reading(int fd, char *str)
{
	char		*buf;
	ssize_t		len;

	buf = malloc(sizeof(char) * (2));
	if (!buf)
		return (NULL);
	len = 1;
	while (len != 0 && !ft_nl_check(str))
	{
		len = read(fd, buf, 1);
		if (len < 0)
		{
			free (buf);
			return (NULL);
		}
		buf[len] = '\0';
		str = ft_strjoin(str, buf);
	}
	free (buf);
	return (str);
}

char	*g_nl(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0)
		return (NULL);
	str = ft_reading(fd, str);
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = ft_rm_line(str);
	return (line);
}
