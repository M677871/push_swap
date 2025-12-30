# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: you <you@student.42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/27                                 #+#    #+#            #
#    Updated: 2025/12/27                                 ###   ########.fr      #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

NAME    = push_swap
BONUS   = checker

SRCS    = push_swap.c \
          parse_values.c \
          parse_sort_utils.c \
          push_swap_parsing.c \
          push_swap_utils.c \
          push_swap_error.c \
          context.c \
          bench.c \
          strategy.c \
          stack_init.c \
          stack_utils.c \
          operations_swap.c \
          operations_push.c \
          operations_rotate.c \
          operations_reverse_rotate.c \
          sort_small.c \
          sort_medium.c \
          sort_big.c \
          sort_adaptive.c

BONUS_SRCS = checker.c checker_readline.c \
          parse_values.c \
          parse_sort_utils.c \
          push_swap_parsing.c \
          push_swap_utils.c \
          push_swap_error.c \
          context.c \
          bench.c \
          stack_init.c \
          stack_utils.c \
          operations_swap.c \
          operations_push.c \
          operations_rotate.c \
          operations_reverse_rotate.c

OBJS    = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
