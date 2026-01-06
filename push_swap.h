/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:14:06 by miissa            #+#    #+#             */
/*   Updated: 2026/01/05 13:47:52 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "Libft/libft.h"
# include "Printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;

}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}					t_op;

typedef enum e_startegy
{
	START_SIMPLE,
	START_MEDIUM,
	START_COMPLEX,
	START_ADAPTIVE,
	START_LOW
}					t_strategy;

typedef struct s_stats
{
	int				count[11];
	int				total;
}					t_stats;

typedef struct s_ctx
{
	int				print_ops;
	int				bench;
	double			disorder;
	t_strategy		selected;
	t_strategy		used;
	t_stats			stats;
}					t_ctx;
void				ps_ctx_init(t_ctx *ctx, int print_ops);
int					ps_parse_flags(int argc, char **argv, t_ctx *ctx,
						int *out_start);
void				ps_cleanup(t_ctx *ctx, t_stack *a, t_stack *b);
void				ps_exit_error(t_ctx *ctx, t_stack *a, t_stack *b, int code);
void				ps_stats_init(t_stats *s);
void				ps_emit_op(t_ctx *ctx, t_op op);
void				ps_print_bench(const t_ctx *ctx);
void				ps_putdouble2_fd(double val, int fd);
void				ps_putpercent2_fd(double val, int fd);
void				stack_reset(t_stack *s);
t_node				*node_create(int value, int index);
void				stack_free_all(t_stack *s);
int					stack_is_sorted_asc(t_stack *s);
int					stack_pos_of_min_index(t_stack *s);
int					stack_pos_of_max_index(t_stack *s);
int					int_array_has_duplicates_sorted(const int *array, int size);
// int					array_find_index(const int *array, int size, int value);
int					ps_parse_argv_to_ints(int argc, char **argv, int start,
						int **out_vals, int *out_n);
const char			*ps_strategy_name(t_strategy s);
const char			*ps_strategy_complexity(t_strategy s);
void				ps_run_strategy(t_stack *a, t_stack *b, t_ctx *ctx);
void				ps_free_split(char **parts);
char				**ps_split_ws(const char *s);
int					ps_parse_token(const char *s, int *out);
int					ps_build_stack_from_args(int argc, char **argv, int start,
						t_stack *a, double *out_disorder);
int					ps_parse_argv_to_ints(int argc, char **argv, int start,
						int **out_vals, int *out_n);
int					int_array_sort_asc(int *arr, int n);
int					int_array_has_duplicates_sorted(const int *sorted, int n);
double				ps_compute_disorder(const int *vals, int n);
int					ps_build_stack_from_args(int argc, char **argv, int start,
						t_stack *a, double *out_disorder);
void				sa(t_stack *a, t_ctx *ctx);
void				sb(t_stack *a, t_ctx *ctx);
void				ss(t_stack *a, t_stack *b, t_ctx *ctx);
void				pa(t_stack *a, t_stack *b, t_ctx *ctx);
void				pb(t_stack *a, t_stack *b, t_ctx *ctx);
void				ra(t_stack *a, t_ctx *ctx);
void				rb(t_stack *b, t_ctx *ctx);
void				rr(t_stack *a, t_stack *b, t_ctx *ctx);
void				rra(t_stack *a, t_ctx *ctx);
void				rrb(t_stack *b, t_ctx *ctx);
void				rrr(t_stack *a, t_stack *b, t_ctx *ctx);
void				sort_simple_using_selection(t_stack *a, t_stack *b,
						t_ctx *ctx);
void				sort_medium_using_chunk(t_stack *a, t_stack *b, t_ctx *ctx);
void				sort_complex(t_stack *a, t_stack *b, t_ctx *ctx);
t_strategy			sort_adaptive(t_stack *a, t_stack *b, t_ctx *ctx);
void				stack_push_front(t_stack *s, t_node *n);
void				stack_push_back(t_stack *s, t_node *n);
t_node				*stack_pop_front(t_stack *s);
t_node				*stack_pop_back(t_stack *s);

#endif