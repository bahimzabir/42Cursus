/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:02:25 by azabir            #+#    #+#             */
/*   Updated: 2021/11/27 23:03:18 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_check(char **s)
{
	while (**s)
	{
		if (**s == '\n')
		{
			*s += 1;
			break ;
		}
		*s += 1;
	}
}

char	*ft_read_file(int fd, char *str)
{
	char	*buff;
	int		len;

	buff = malloc((1 + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	len = 1;
	while (len > 0 && buff)
	{
		len = read(fd, buff, 1);
		if (len < 0)
		{
			free (str);
			free(buff);
			return (NULL);
		}
		buff[len] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	static char	*k;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
	{	
		str = ft_read_file(fd, str);
		if (!str || !*str)
			return (NULL);
		k = str;
	}
	line = ft_strdup(str, k);
	if (line == NULL)
	{
		free(line);
		return (NULL);
	}
	ft_check(&str);
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open ("test2.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	/*printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);*/
}
