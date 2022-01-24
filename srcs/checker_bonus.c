/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:10:01 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/21 23:46:09 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	lists_clear(t_list *a, t_list *b)
{
	list_clear(a);
	list_clear(b);
}

static int	do_instruction(t_list *a, t_list *b, char *line)
{
	if (!ft_strncmp(line, "rra", 4))
		reverse_rotate(a);
	else if (!ft_strncmp(line, "rrb", 4))
		reverse_rotate(b);
	else if (!ft_strncmp(line, "rrr", 4))
		rrr_reverse_rotate(a, b);
	else if (!ft_strncmp(line, "pb", 3))
		push(a, b);
	else if (!ft_strncmp(line, "pa", 3))
		push(b, a);
	else if (!ft_strncmp(line, "ra", 3))
		rotate(a);
	else if (!ft_strncmp(line, "rb", 3))
		rotate(b);
	else if (!ft_strncmp(line, "rr", 3))
		rr_rotate(a, b);
	else if (!ft_strncmp(line, "sa", 3))
		swap(a);
	else if (!ft_strncmp(line, "sb", 3))
		swap(b);
	else if (!ft_strncmp(line, "ss", 3))
		ss_swap(a, b);
	else
		return (0);
	return (1);
}

static void	sort_checker(t_list *a, t_list *b)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (!do_instruction(a, b, line))
		{
			lists_clear(a, b);
			ft_putstr_fd("Error\n", 2);
			free(line);
			exit(1);
		}
		free(line);
	}
	if (sorted(a) && b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		clear;

	clear = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		clear = 1;
		argv = ft_split(argv[1], ' ', &argc);
	}
	a = list_init();
	parse_args(argc, argv, a, clear);
	b = list_init();
	sort_checker(a, b);
	lists_clear(a, b);
	return (0);
}
