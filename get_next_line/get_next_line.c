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

void	ft_check(char *s, int *i)
{
	*i = 0;
	while (s[*i] != '\0')
	{
		if (s[*i] == '\n' || s[*i + 1] == '\0')
			break ;
		*i += 1;
	}
}

char	*ft_read_file(int fd, char *str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = read(fd, buff, BUFFER_SIZE);
	if (rd_bytes <= 0)
	{
		free(buff);
		free(str);
		return (NULL);
	}
	buff[rd_bytes] = '\0';
	while (rd_bytes > 0)
	{
		str = ft_strjoin(str, buff);
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	int			i;
	static char	*k;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
	{	
		str = malloc(sizeof(char) * 1);
		str[0] = 0;
		str = ft_read_file(fd, str);
		if (!str || !*str)
			return (NULL);
		else
			k = str;
	}
	line = ft_strdup(str);
	if (line == NULL)
	{
		free (line);
		if (k)
		{
			//printf("\nYEEEEY\n");
			free (k);
		}
		return (NULL);
	}
	ft_check(str, &i);
	str = str + i + 1;
	//printf("\n%c\n", *(str - 2));
	return (line);
}
/*
int	main(void)
{
	int	fd;

	fd = open ("test2.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
}*/