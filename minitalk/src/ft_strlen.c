/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:29:50 by azabir            #+#    #+#             */
/*   Updated: 2021/11/06 13:43:28 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minitalk.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*str++ != '\0')
		i++;
	return (i);
}
