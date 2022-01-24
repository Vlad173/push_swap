/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:41:33 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/21 23:36:54 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	arg_is_valid(char *str)
{
	if (*str == '0' && *(str + 1) == '\0')
		return (1);
	if (*str == '-' || *str == '+')
		++str;
	if (!str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		++str;
	}
	return (1);
}

static int	check_duplicate(t_list *a, int num)
{
	t_list_el	*it;

	it = a->head;
	while (it)
	{
		if (num == it->value.num)
			return (0);
		it = it->next;
	}
	return (1);
}

void	clear_argv(char *argv[], int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		free(argv[i]);
		++i;
	}
	free(argv);
}

void	cerror(t_list *a, int argc, char *argv[], int clear)
{
	if (clear)
		clear_argv(argv, argc);
	list_clear(a);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	parse_args(int argc, char *argv[], t_list *a, int clear)
{
	int			i;
	long long	check;
	t_value		value;

	if (argv == NULL)
		cerror(a, argc, argv, 0);
	i = 1;
	while (i < argc)
	{
		if (!arg_is_valid(argv[i]))
			cerror(a, argc, argv, clear);
		check = ft_atoi(argv[i]);
		if (check > INT_MAX || check < INT_MIN)
			cerror(a, argc, argv, clear);
		if (!check_duplicate(a, check))
			cerror(a, argc, argv, clear);
		value.num = check;
		if (!push_back(a, value))
			cerror(a, argc, argv, clear);
		++i;
	}
	if (clear)
		clear_argv(argv, argc);
}
