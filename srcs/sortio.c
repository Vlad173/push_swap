/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortio.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:36:10 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/21 15:08:09 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_duo(t_list *a)
{
	if (a->head->value.num > a->head->next->value.num)
	{
		swap(a);
		ft_putstr_fd("sa\n", 1);
	}
}

static void	sort_trio(t_list *a)
{
	int	first;
	int	second;
	int	third;

	first = a->head->value.num;
	second = a->head->next->value.num;
	third = a->head->next->next->value.num;
	if ((first < third && third < second)
		|| (first > second && second > third)
		|| (first > second && third > first))
	{
		swap(a);
		ft_putstr_fd("sa\n", 1);
	}
}

static void	find_trio(t_list_el *it, int *min, int *max, int *mid)
{
	t_list		*temp;
	t_list_el	*a;
	t_value		value;
	int			i;

	temp = list_init();
	while (it)
	{
		value.num = it->value.num;
		push_back(temp, value);
		it = it->next;
	}
	sort_list(temp);
	*min = temp->head->value.num;
	*max = temp->tail->value.num;
	*mid = temp->size / 2;
	i = -1;
	a = temp->head;
	while (++i < *mid - 1)
		a = a->next;
	*mid = a->value.num;
	list_clear(temp);
}

void	do_trio(t_list *a, t_list *b)
{
	int		min;
	int		max;
	int		mid;
	int		check;

	find_trio(a->head, &min, &max, &mid);
	while (a->size != 3)
	{
		check = a->head->value.num;
		if (check == min || check == max || check == mid)
		{
			rotate(a);
			ft_putstr_fd("ra\n", 1);
		}
		else
		{
			push(a, b);
			ft_putstr_fd("pb\n", 1);
		}
	}
	sort_trio(a);
}
