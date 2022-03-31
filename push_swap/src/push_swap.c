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
	printf("-----------------\n");
	if (tmp)
	{
		while (tmp)
		{
			printf("%d ", tmp->data);
			tmp = tmp->next;
		}
	}
	printf("\n-----------------\n");
}
void	print_index(t_list *tmp)
{
	if (tmp)
	{
		while (tmp)
		{
			printf("%d\n", tmp->index);
			tmp = tmp->next;
		}
	}
	printf("\n#####\n");
}

/*void	push_swap1(t_list **sta, t_list **stb, int arc)
{
	int		i;
	int		j;
	t_list	*temp;

	temp = *sta;
	i = 1;
	j = 0;
	while (i <= arc)
	{
		
		while (((*sta)->index != i) && (check_order(*sta) == 0))
			do_move(sta, stb, arc, i);
		if ((i == arc || check_order(*sta) == 1) && !(*stb))
			break;
		if (check_order(*sta) == 0)
			ft_pb(sta, stb);
		i++;
		if (i == arc && check_order(*sta) == 1)
			while (i >= 1)
			{
				ft_pa(sta, stb);
				i--;
			}
		if (i == 0)
			break;
	}
}*/

void	ft_move2(t_list **stb, t_list **sta, int c)
{
	int		count;
	t_list	*temp;

	count = 1;
	temp = *stb;
	while (temp && temp->index - (*sta)->index != -1)
	{
		temp = temp->next;
		count++;
	}
	if (count <= c/2 + 1)
		while ((*stb) && (((*sta)->index) - ((*stb)->index)) != 1)
			ft_rb(stb);
	else
		while ((*stb) && (*stb)->index - (*sta)->index != -1)
			ft_rrb(stb);
}

void	push_swap1(t_list **sta, t_list **stb, int arc)
{
	int		i;
	int		j;
	int		c;

	i = arc / 5;
	j = 1;
	c = 0;
	while (!(*stb) && !check_order(*sta))
	{
		while (check_order(*sta) == 0 || i >= arc)
		{
			if ((*sta)->index <= i)
			{
				ft_pb(sta, stb);
				c++;
			}
			else
				ft_ra(sta);
			if (j >= arc)
			{
				i = i + arc / 5;

				j = 0;
			}
			j++;
		}
		while (*stb)
		{
			if ((*sta)->index - (*stb)->index == 1)
			{
				ft_pa(sta, stb);
				c--;
			}
			else
				ft_move2(stb, sta, c);
		}
	}
}

int	main(int arc, char **arv)
{
	t_list	*sta;
	t_list	*stb;

	stb = NULL;
	if (arc <= 1)
		return (1);
	arr_to_list(arv, &sta);
	indexing(&sta, arc);
	if (arc <= 51)
		push_swap1(&sta, &stb, arc - 1);
	if (arc <= 502)
		push_swap1(&sta, &stb, arc - 1);

	return (0);
}
