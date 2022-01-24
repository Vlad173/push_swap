/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:33:32 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/21 23:43:38 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef enum s_final
{
	RR_RA,
	RR_RB,
	RRR_RRA,
	RRR_RRB,
	RA_RRB,
	RB_RRA
}	t_final;

typedef enum e_operation
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_operation;

typedef struct s_value
{
	int			num;
	int			a_up;
	int			b_up;
	int			a_down;
	int			b_down;
	t_final		type;
}	t_value;

typedef struct s_list_el
{
	t_value				value;
	struct s_list_el	*next;
	struct s_list_el	*prev;
}	t_list_el;

typedef struct s_list
{
	t_list_el	*head;
	t_list_el	*tail;
	int			size;
}	t_list;

// list functions
int		push_back(t_list *list, t_value value);
void	list_clear(t_list *list);
t_list	*list_init(void);
void	sort_list(t_list *list);

// operations
void	swap(t_list *list);
void	push(t_list *a, t_list *b);
void	ss_swap(t_list *first, t_list *second);
void	push(t_list *a, t_list *b);
void	rotate(t_list *list);
void	rr_rotate(t_list *first, t_list *second);
void	reverse_rotate(t_list *list);
void	rrr_reverse_rotate(t_list *first, t_list *second);

void	parse_args(int argc, char *argv[], t_list *a, int clear);
void	sort(t_list *a, t_list *b);
void	do_duo(t_list *a);
void	do_trio(t_list *a, t_list *b);
int		get_min(t_list_el *l);
void	do_operations(t_list *a, t_list *b, int pos);
void	do_rrr_rra(t_list *a, t_list *b, t_list_el *todo);
void	do_rrr_rrb(t_list *a, t_list *b, t_list_el *todo);
void	do_ra_rrb(t_list *a, t_list *b, t_list_el *todo);
void	do_rb_rra(t_list *a, t_list *b, t_list_el *todo);
void	do_rr_rb(t_list *a, t_list *b, t_list_el *todo);
void	do_rr_ra(t_list *a, t_list *b, t_list_el *todo);
void	final_sort(t_list *list);
int		insert_cond(int first, int second, int third);
void	clear_argv(char *argv[], int argc);
int		get_next_line(int fd, char **res);
int		sorted(t_list *list);

#endif
