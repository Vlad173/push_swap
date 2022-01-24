/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:10:01 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/21 23:45:41 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	sort(a, b);
	list_clear(a);
	list_clear(b);
	return (0);
}
