/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:56:54 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/21 10:42:58 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_rr_rb(t_list *a, t_list *b, t_list_el *todo)
{
	int	i;

	i = 0;
	while (i < todo->value.a_up)
	{
		rr_rotate(a, b);
		ft_putstr_fd("rr\n", 1);
		++i;
	}
	while (i < todo->value.b_up)
	{
		rotate(b);
		ft_putstr_fd("rb\n", 1);
		++i;
	}
}

void	do_rrr_rra(t_list *a, t_list *b, t_list_el *todo)
{
	int	i;

	i = 0;
	while (i < todo->value.b_down)
	{
		rrr_reverse_rotate(a, b);
		ft_putstr_fd("rrr\n", 1);
		++i;
	}
	while (i < todo->value.a_down)
	{
		reverse_rotate(a);
		ft_putstr_fd("rra\n", 1);
		++i;
	}
}

void	do_rrr_rrb(t_list *a, t_list *b, t_list_el *todo)
{
	int	i;

	i = 0;
	while (i < todo->value.a_down)
	{
		rrr_reverse_rotate(a, b);
		ft_putstr_fd("rrr\n", 1);
		++i;
	}
	while (i < todo->value.b_down)
	{
		reverse_rotate(b);
		ft_putstr_fd("rrb\n", 1);
		++i;
	}
}

void	do_ra_rrb(t_list *a, t_list *b, t_list_el *todo)
{
	int	i;

	i = 0;
	while (i < todo->value.a_up)
	{
		rotate(a);
		ft_putstr_fd("ra\n", 1);
		++i;
	}
	i = 0;
	while (i < todo->value.b_down)
	{
		reverse_rotate(b);
		ft_putstr_fd("rrb\n", 1);
		++i;
	}
}

void	do_rb_rra(t_list *a, t_list *b, t_list_el *todo)
{
	int	i;

	i = 0;
	while (i < todo->value.b_up)
	{
		rotate(b);
		ft_putstr_fd("rb\n", 1);
		++i;
	}
	i = 0;
	while (i < todo->value.a_down)
	{
		reverse_rotate(a);
		ft_putstr_fd("rra\n", 1);
		++i;
	}
}
