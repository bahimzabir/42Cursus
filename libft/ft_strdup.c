/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:55:45 by azabir            #+#    #+#             */
/*   Updated: 2021/11/09 13:48:18 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	s2 = (char *)malloc(i * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
/*
int main()
{
	const char	*s1;
	char		*s2;
	char		*s3;

	s1 = "Katbghiw Ha Taghiya";
	s2 = strdup(s1);
	s3 = ft_strdup(s1);
	printf("%s\n%s\n", s2, s3);
	free(s2);
	free(s3);	
}*/
