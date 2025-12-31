# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: you <you@student.42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/27                                 #+#    #+#            #
#    Updated: 2025/12/30                                 ###   ########.fr      #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I . -I libft

NAME    = push_swap
LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

SRCS    = push_swap.c \
          context.c \
          push_swap_error.c \
          push_swap_utils.c \
          stats_emit.c \
          bench.c \
          strategy.c \
          stack_init.c \
          stack_utils.c \
          parse_tokens.c \
          parse_values.c \
          parse_sort_utils.c \
          push_swap_parsing.c \
          operations_swap.c \
          operations_push.c \
          operations_rotate.c \
          operations_reverse_rotate.c \
          sort_small.c \
          sort_medium.c \
          sort_big.c \
          sort_adaptive.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
