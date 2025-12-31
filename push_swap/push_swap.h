/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/30                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				idx;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
} t_stack;

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
} t_op;

typedef enum e_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE,
	STRAT_LOW
} t_strategy;

typedef struct s_stats
{
	int	counts[11];
	int	total;
} t_stats;

typedef struct s_ctx
{
	int			print_ops;
	int			bench;
	double		disorder;
	t_strategy	selected;
	t_strategy	used;
	t_stats		stats;
} t_ctx;

/* context / flags */
void		ps_ctx_init(t_ctx *ctx, int print_ops);
int			ps_parse_flags(int argc, char **argv, t_ctx *ctx, int *out_start);

/* cleanup / error */
void		ps_cleanup(t_ctx *ctx, t_stack *a, t_stack *b);
void		ps_exit_error(t_ctx *ctx, t_stack *a, t_stack *b, int code);

/* stats / op emitter */
void		ps_stats_init(t_stats *s);
void		ps_emit_op(t_ctx *ctx, t_op op);

/* printing / bench */
void		ps_putdouble2_fd(double val, int fd);
void		ps_putpercent2_fd(double val, int fd);
void		ps_print_bench(const t_ctx *ctx);

/* strategy */
const char	*ps_strategy_name(t_strategy s);
const char	*ps_strategy_complexity(t_strategy s);
void		ps_run_strategy(t_stack *a, t_stack *b, t_ctx *ctx);

/* stack core */
void		stack_reset(t_stack *s);
t_node		*node_create(int value, int idx);
void		stack_push_front(t_stack *s, t_node *n);
void		stack_push_back(t_stack *s, t_node *n);
t_node		*stack_pop_front(t_stack *s);

/* stack utils */
t_node		*stack_pop_back(t_stack *s);
void		stack_free_all(t_stack *s);
int			stack_is_sorted_asc(t_stack *a);
int			stack_pos_of_min_idx(t_stack *a);
int			stack_pos_of_max_idx(t_stack *a);

/* parsing */
int			ps_parse_argv_to_ints(int argc, char **argv, int start,
				int **out_vals, int *out_n);
int			int_array_sort_asc(int *arr, int n);
int			int_array_has_duplicates_sorted(const int *sorted, int n);
double		ps_compute_disorder(const int *vals, int n);
int			ps_build_stack_from_args(int argc, char **argv, int start,
				t_stack *a, double *out_disorder);

/* operations */
void		sa(t_stack *a, t_ctx *ctx);
void		sb(t_stack *b, t_ctx *ctx);
void		ss(t_stack *a, t_stack *b, t_ctx *ctx);
void		pa(t_stack *a, t_stack *b, t_ctx *ctx);
void		pb(t_stack *a, t_stack *b, t_ctx *ctx);
void		ra(t_stack *a, t_ctx *ctx);
void		rb(t_stack *b, t_ctx *ctx);
void		rr(t_stack *a, t_stack *b, t_ctx *ctx);
void		rra(t_stack *a, t_ctx *ctx);
void		rrb(t_stack *b, t_ctx *ctx);
void		rrr(t_stack *a, t_stack *b, t_ctx *ctx);

/* sorting */
void		sort_simple(t_stack *a, t_stack *b, t_ctx *ctx);
void		sort_medium(t_stack *a, t_stack *b, t_ctx *ctx);
void		sort_complex(t_stack *a, t_stack *b, t_ctx *ctx);
t_strategy	sort_adaptive(t_stack *a, t_stack *b, t_ctx *ctx);

#endif
