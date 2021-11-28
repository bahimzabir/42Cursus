/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:59:57 by azabir            #+#    #+#             */
/*   Updated: 2021/11/14 14:09:28 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{	
	if (s)
		write(fd, s, ft_strlen(s));
}
/*
int	main(void)
{
	int	fd;
	char	s[] = "KHIT BYAD";
	fd = open("test.txt", O_CREAT | O_RDWR);
	ft_putstr_fd(s, fd);
}*/
