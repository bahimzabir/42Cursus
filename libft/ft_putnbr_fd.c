/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:09:18 by azabir            #+#    #+#             */
/*   Updated: 2021/11/14 17:34:44 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	r;
	char			*c;

	c = "0123456789";
	if (n < 0)
	{
		r = -n;
		write(fd, "-", 1);
	}
	else
		r = n;
	if (r >= 10)
	{
		ft_putnbr_fd(r / 10, fd);
		write(fd, &c[r % 10], 1);
	}
	else
		write(fd, &c[r % 10], 1);
}
/*
int	main(void)
{
	int	fd;

	fd = open("test3.txt", O_CREAT | O_RDWR);
	ft_putnbr_fd(0, fd);
}*/
