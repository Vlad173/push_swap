/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:04:48 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/21 11:26:18 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	insert_cond(int first, int second, int third)
{
	if (first < second && second < third)
		return (1);
	if (first > second && second < third && first > third)
		return (1);
	if (first < second && second > third && first > third)
		return (1);
	return (0);
}

static int	get_min_helper(t_list_el *l, int min)
{
	if (l->value.b_down > l->value.a_down)
	{
		if (min > l->value.b_down)
		{
			min = l->value.b_down;
			l->value.type = RRR_RRB;
		}
	}
	else
	{
		if (min > l->value.a_down)
		{
			min = l->value.a_down;
			l->value.type = RRR_RRA;
		}
	}
	return (min);
}

int	get_min(t_list_el *l)
{
	int	min;

	if (l->value.b_up > l->value.a_up)
	{
		min = l->value.b_up;
		l->value.type = RR_RB;
	}
	else
	{
		min = l->value.a_up;
		l->value.type = RR_RA;
	}
	if (min > l->value.b_up + l->value.a_down)
	{
		min = l->value.b_up + l->value.a_down;
		l->value.type = RB_RRA;
	}
	if (min > l->value.b_down + l->value.a_up)
	{
		min = l->value.b_down + l->value.a_up;
		l->value.type = RA_RRB;
	}
	min = get_min_helper(l, min);
	return (min);
}

void	do_rr_ra(t_list *a, t_list *b, t_list_el *todo)
{
	int	i;

	i = 0;
	while (i < todo->value.b_up)
	{
		rr_rotate(a, b);
		ft_putstr_fd("rr\n", 1);
		++i;
	}
	while (i < todo->value.a_up)
	{
		rotate(a);
		ft_putstr_fd("ra\n", 1);
		++i;
	}
}

void	do_operations(t_list *a, t_list *b, int pos)
{
	t_list_el	*it;

	it = b->head;
	while (pos)
	{
		it = it->next;
		--pos;
	}
	if (it->value.type == RR_RA)
		do_rr_ra(a, b, it);
	else if (it->value.type == RR_RB)
		do_rr_rb(a, b, it);
	else if (it->value.type == RRR_RRA)
		do_rrr_rra(a, b, it);
	else if (it->value.type == RRR_RRB)
		do_rrr_rrb(a, b, it);
	else if (it->value.type == RA_RRB)
		do_ra_rrb(a, b, it);
	else if (it->value.type == RB_RRA)
		do_rb_rra(a, b, it);
}
