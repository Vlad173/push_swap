/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:51:37 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/21 15:27:37 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	final(t_list *list, int pos)
{
	if (pos < list->size / 2 + 1)
	{
		while (pos)
		{
			rotate(list);
			ft_putstr_fd("ra\n", 1);
			--pos;
		}
	}
	else
	{
		while (list->size - pos)
		{
			reverse_rotate(list);
			ft_putstr_fd("rra\n", 1);
			++pos;
		}
	}
}

void	final_sort(t_list *list)
{
	t_list_el	*it;
	int			pos;
	int			min;
	int			i;

	min = INT_MAX;
	pos = 0;
	i = 0;
	it = list->head;
	while (it)
	{
		if (min > it->value.num)
		{
			min = it->value.num;
			pos = i;
		}
		++i;
		it = it->next;
	}
	final(list, pos);
}
