/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:33:22 by azabir            #+#    #+#             */
/*   Updated: 2022/03/20 17:34:16 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arr_to_list(char **arr, t_list **stack_list)
{
	int	i;

	i = 2;
	*stack_list = lstmake (ft_atoi(arr[1]));
	while (arr [i])
	{
		lstaddback(*stack_list, ft_atoi(arr[i]));
		i++;
	}
}

void	print_list(t_list *tmp)
{
	if (tmp)
	{
	while (tmp && tmp->next != NULL)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	printf("%d\n######\n", tmp->data);
	}
}

int	main(int arc, char **arv)
{
	t_list	*sta;
	t_list	*stb;

	if (arc <= 1)
		return (1);
	arr_to_list(arv, &sta);
	print_list(sta);
	return (0);
}
