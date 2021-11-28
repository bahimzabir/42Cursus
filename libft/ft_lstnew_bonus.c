/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 02:01:58 by azabir            #+#    #+#             */
/*   Updated: 2021/11/21 03:33:04 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (0);
	head -> content = content;
	head -> next = NULL;
	return (head);
}
/*
int	main()
{
	char	c[] = "content";
	t_list	*t;

	t = ft_lstnew(c);
	printf("%s\n", (char *)t->content);
}*/