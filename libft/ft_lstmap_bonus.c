/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 23:56:21 by azabir            #+#    #+#             */
/*   Updated: 2021/11/20 02:08:28 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	*f(void *i)
{
	*(int *)i = *(int *)i + 1;
	return (i);
}
void	del(void *i)
{
	*(int *)i = 0;
	free (i);
}
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*first;

	if (!lst)
		return (0);
	nlst = ft_lstnew(f(lst->content));
	if (!nlst)
		return (0);
	first = nlst;
	lst = lst -> next;
	while (lst)
	{
		nlst->next = ft_lstnew(f(lst->content));
		if (!(nlst->next))
		{
			ft_lstclear(&first, del);
			free (nlst);
			return (0);
		}
		nlst = nlst -> next;
		lst = lst->next;
	}
	nlst -> next = NULL;
	return (first);
}
/*
int	main(void)
{
	t_list	*lst;
	int	i;

	i = 1;
	int	arr[] = {1, 2, 3, 4};
	lst = ft_lstnew(arr);

	while (i < 4)
	{
		ft_lstadd_back(&lst, ft_lstnew(arr + i));
		i++;
	}
	t_list	*t = ft_lstmap(lst, f, del);
	while (t)
	{
		printf("%d", *(int *)t->content);
		t = t->next;
	}
}*/