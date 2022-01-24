# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 08:44:57 by pmeredyt          #+#    #+#              #
#    Updated: 2022/01/21 23:50:59 by pmeredyt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_CHECKER = checker 

SRC_SORTER = main.c

SRC_COMMON = list.c parse_args.c push_swap.c rotate.c sort.c \
			 sortio.c sort_utils.c operations.c \
			 final_sort.c

SRC_CHECKER = get_next_line_bonus.c checker_bonus.c

SRC_DIR = srcs

HEADER = includes/push_swap.h

OBJS_SORTER = $(addprefix $(SRC_DIR)/,$(SRC_SORTER:.c=.o))
OBJS_COMMON = $(addprefix $(SRC_DIR)/,$(SRC_COMMON:.c=.o))
OBJS_CHECKER = $(addprefix $(SRC_DIR)/,$(SRC_CHECKER:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FT = -L libft -lft

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS_SORTER) $(OBJS_COMMON)
	@make -C libft
	$(CC) -o $@ $^ $(FT)

$(NAME_CHECKER): $(OBJS_CHECKER) $(OBJS_COMMON)
	@make -C libft
	$(CC) -o $@ $^ $(FT)
	
bonus: $(NAME_CHECKER)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C libft/ clean
	@$(RM) $(OBJS_COMMON) $(OBJS_SORTER) $(OBJS_CHECKER)

fclean: clean
	@make -C libft/ fclean
	@$(RM) $(NAME) $(NAME_CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus
