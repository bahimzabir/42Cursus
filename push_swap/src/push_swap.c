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

void	push_swap1(t_list **sta, t_list **stb, int arc)
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
}

int	lst_counter(t_list *list)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = list;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	range_move(t_list **sta, int i)
{
	int		count;
	int		size;
	t_list	*temp;

	temp = *sta;
	count = 0;
	size = lst_counter(temp);
	if ((*sta)->next && (*sta)->index - (*sta)->next->index == 1)
		ft_sa(sta);
	while (temp->index <= i)
	{
		temp = temp->next;
		count++;	
	}
	if (!check_order(*sta))
	{
		if (count <= size/2 + 1)
			ft_ra(sta);
		else
			ft_rra(sta);
	}

}

int	range_check(t_list *list, int i)
{
	t_list	*temp;

	temp = list;
	while (temp)
	{
		if (temp->index <= i)
			return (1);
		temp = temp->next;
	}
	return (0);
}

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
		while ((*stb) && (*stb)->index - (*sta)->index != -1 )
			ft_rrb(stb);
}

t_list	*big_sort(t_list *list)
{
	t_list	*temp1;
	t_list	*temp2;
	t_list	*temp3;
	int		i;
	int		j;

	temp1 = list;
	temp3 = list;
	i = 0;
	j = 0;
	while (temp1->next)
	{	
		temp2 = temp1;
		i = 0;
		while (temp1->next && temp1->index - temp1->next->index == 1)
		{
			i++;
			temp1 = temp1->next;
		}
		if (i > j)
		{
			j = i;
			temp3 = temp2;
		}
	}
	return (temp3);
}

int	list_end(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp->next)
		temp = temp->next;
	return (temp->index);
}
void	ft_move3(t_list **stb, t_list **sta, int c)
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
	temp = big_sort(*stb);
	if ((*stb)->index == temp->index && (*sta)->index - (*stb)->index != 1)
		while (temp->index - temp->next->index == 1)
		{
			ft_pa(sta, stb);
			ft_ra(sta);
			temp = temp->next;
				if (temp->index == list_end(temp))
					break;
		}

	if (count <= c/2 + 1)
		while ((*stb) && (((*sta)->index) - ((*stb)->index)) != 1)
			ft_rb(stb);
	else
		while ((*stb) && (*stb)->index - (*sta)->index != -1 )
			ft_rrb(stb);
}

void	push_swap2(t_list **sta, t_list **stb, int arc)
{
	int		i;
	int		j;
	int		c;

	i = arc / 5;
	j = 1;
	c = 0;
	while (!(*stb) && !check_order(*sta))
	{
		while (check_order(*sta) == 0)
		{
			if ((*sta)->index <= i)
				ft_pb(sta, stb);
			else if(range_check(*sta, i))
				range_move(sta, i);
			if (j >= arc)
			{
				i = i + arc / 5;
				if (i >= arc)
					i = arc - 1;
				j = 0;
			}
			j++;
		}
		while (*stb)
		{
			if ((*sta)->index - (*stb)->index == 1)
				ft_pa(sta, stb);
			else
				ft_move2(stb, sta, lst_counter(*stb));
		}
	}
}


void	push_swap3(t_list **sta, t_list **stb, int arc)
{
	int		i;
	int		j;
	int		c;

	i = arc / 8;
	j = 1;
	c = 0;
	while (!(*stb) && !check_order(*sta))
	{
		while ((*sta) && check_order(*sta) == 0)
		{
			if ((*sta)->index >= arc / 2 - i && (*sta)->index <= arc / 2 + i + 1)
				ft_pb(sta, stb);
			else if(range_check(*sta, i))
				range_move(sta, i);
			if ((*stb) && (*stb)->index <= arc / 2 - arc / 4)
				ft_rb(stb);
			if (j >= arc)
			{
				i = i + arc / 8;
				if (i >= arc / 2)
					i = arc / 2;
				j = 0;
			}
			j++;
			// print_list (*sta);
			// printf ("%d\n", i);
			// printf ("%d\n", arc);
		}
		while (*stb)
		{
			if ((*sta)->index - (*stb)->index == 1)
				ft_pa(sta, stb);
			else
				ft_move2(stb, sta, lst_counter(*stb));
			/*if ((*sta)->index - list_end(*sta) == -1)
				ft_rra(sta);*/
		}
		//write (1, "HERE\n", 5);
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
		push_swap3(&sta, &stb, arc - 1);
		//print_list (sta);
		//print_list (stb);

	return (0);
}
