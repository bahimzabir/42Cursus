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
	while (s[*i] != '\0')
	{
		if (s[*i] == '\n')
			break ;
		*i += 1;
	}
}

char	*get_next_line(int fd)
{
	static char			*str = "";
	char				*tmp;
	ssize_t				len;
	int					i;
	char				*save;

	i = 0;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (0);
	len = read(fd, tmp, BUFFER_SIZE);
	while (len > 0)
	{
		tmp[len] = '\0';
		str = ft_strjoin(str, tmp);
		len = read(fd, tmp, BUFFER_SIZE);
	}
	free(tmp);
	save = ft_strdup(str);
	if (*save == '\0')
		return (NULL);
	ft_check(str, &i);
	str = str + i + 1;
	save[i + 1] = '\0';
	return (save);
}
/*
int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
*/