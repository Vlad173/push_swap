/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:38:33 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/21 23:45:33 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	condition_for_insert(t_list *a, t_list_el *b, t_list_el *it, int i)
{
	if (!it->next)
	{
		b->value.a_up = 0;
		b->value.a_down = a->size;
		return (1);
	}
	if (insert_cond(it->value.num, b->value.num, it->next->value.num))
	{
		b->value.a_up = i + 1;
		b->value.a_down = a->size - i - 1;
		return (1);
	}
	return (0);
}

static void	up_downs(t_list *a, t_list_el *b, int pos, size_t b_size)
{
	int			i;
	t_list_el	*it;

	b->value.b_up = pos;
	if (b_size == 1)
		b->value.b_down = 0;
	else
		b->value.b_down = b_size - pos;
	i = 0;
	it = a->head;
	while (it)
	{
		if (condition_for_insert(a, b, it, i))
			break ;
		++i;
		it = it->next;
	}
}

static int	find_min(t_list *a, t_list *b)
{
	t_list_el	*it;
	int			min_pos;
	int			min;
	int			i;

	i = 0;
	it = b->head;
	min = INT_MAX;
	while (it)
	{
		up_downs(a, it, i, b->size);
		if (min > get_min(it))
		{
			min_pos = i;
			min = get_min(it);
		}
		++i;
		it = it->next;
	}
	return (min_pos);
}

int	sorted(t_list *list)
{
	t_list_el	*it;

	if (list->size == 0)
		return (0);
	it = list->head;
	while (it->next)
	{
		if (it->value.num > it->next->value.num)
			return (0);
		it = it->next;
	}	
	return (1);
}

void	sort(t_list *a, t_list *b)
{
	int	min;

	if (a->size == 1)
		return ;
	if (a->size == 2)
		return (do_duo(a));
	if (sorted(a))
		return ;
	do_trio(a, b);
	while (b->size != 0)
	{
		min = find_min(a, b);
		do_operations(a, b, min);
		push(b, a);
		ft_putstr_fd("pa\n", 1);
	}
	final_sort(a);
}
