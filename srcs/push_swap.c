/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:13:35 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/21 22:19:52 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list *list)
{
	t_list_el	*first;
	t_list_el	*second;

	if (list->size < 2)
		return ;
	first = list->head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	list->head = second;
	if (list->tail == second)
		list->tail = first;
	if (list->size > 2)
		first->next->prev = first;
}

void	ss_swap(t_list *first, t_list *second)
{
	swap(first);
	swap(second);
}

void	push(t_list *a, t_list *b)
{
	t_list_el	*new_el;

	if (a->size == 0)
		return ;
	new_el = a->head;
	if (a->size == 1)
	{
		a->head = NULL;
		a->tail = NULL;
	}
	else
	{
		a->head = a->head->next;
		a->head->prev = NULL;
	}
	new_el->next = b->head;
	if (b->size != 0)
		b->head->prev = new_el;
	b->head = new_el;
	if (b->size == 0)
		b->tail = new_el;
	--a->size;
	++b->size;
}
