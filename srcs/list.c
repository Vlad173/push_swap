/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:17:15 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/21 10:41:53 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*list_init(void)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (result == NULL)
		return (NULL);
	result->head = NULL;
	result->tail = NULL;
	result->size = 0;
	return (result);
}

static t_list_el	*lstnew(t_value content)
{
	t_list_el	*new_el;

	new_el = (t_list_el *)malloc(sizeof(t_list_el));
	if (new_el == NULL)
		return (new_el);
	new_el->next = NULL;
	new_el->prev = NULL;
	new_el->value = content;
	return (new_el);
}

int	push_back(t_list *list, t_value value)
{
	if (!list->head)
	{
		list->head = lstnew(value);
		if (list->head == NULL)
			return (0);
		list->tail = list->head;
	}
	else
	{
		list->tail->next = lstnew(value);
		if (list->tail->next == NULL)
			return (0);
		list->tail->next->prev = list->tail;
		list->tail = list->tail->next;
	}
	++list->size;
	return (1);
}

void	sort_list(t_list *list)
{
	t_list_el	*i;
	t_list_el	*j;
	int			temp;

	i = list->head;
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			if (i->value.num > j->value.num)
			{
				temp = i->value.num;
				i->value.num = j->value.num;
				j->value.num = temp;
			}
			j = j->next;
		}
		i = i->next;
	}
}

void	list_clear(t_list *list)
{
	t_list_el	*it;
	t_list_el	*temp;

	it = list->head;
	while (it)
	{
		temp = it;
		it = it->next;
		free(temp);
	}
	free(list);
}
