/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:33:55 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/21 22:23:54 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_list *list)
{
	if (list->size == 0)
		return ;
	list->tail->next = list->head;
	list->head->prev = list->tail;
	list->head = list->head->next;
	list->tail = list->tail->next;
	list->head->prev = NULL;
	list->tail->next = NULL;
}

void	rr_rotate(t_list *first, t_list *second)
{
	rotate(first);
	rotate(second);
}

void	reverse_rotate(t_list *list)
{
	if (list->size == 0)
		return ;
	list->tail->next = list->head;
	list->head->prev = list->tail;
	list->tail = list->tail->prev;
	list->head = list->head->prev;
	list->head->prev = NULL;
	list->tail->next = NULL;
}

void	rrr_reverse_rotate(t_list *first, t_list *second)
{
	reverse_rotate(first);
	reverse_rotate(second);
}
