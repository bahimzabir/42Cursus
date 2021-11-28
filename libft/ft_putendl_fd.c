/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:30:12 by azabir            #+#    #+#             */
/*   Updated: 2021/11/14 15:48:34 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;

	if (s)
	{
		i = ft_strlen(s);
		write (fd, s, i);
		write (fd, "\n", 1);
	}
}

int	main(void)
{
	int	fd;
	char	s[] = "KHdasdasdaIT BYAD2";
	fd = creat("tesadadadst.txt", O_RDWR);
	ft_putendl_fd(s, fd);
	return (0);
}