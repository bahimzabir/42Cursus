/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 04:00:23 by azabir            #+#    #+#             */
/*   Updated: 2021/11/19 04:26:13 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		new -> next = *lst;
		*lst = new;
	}
}
/*int main()
{
	t_list	*lst;
	t_list	*new;
	
	new = ft_lstnew("new");
	lst = ft_lstnew("content");
	lst -> next = ft_lstnew("content2");
	//ft_lstadd_front(&lst, new);
	printf("%s", lst -> next -> content);
}*/