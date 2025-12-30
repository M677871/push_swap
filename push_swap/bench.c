/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/27                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stats_init(t_stats *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (i < 11)
		s->counts[i++] = 0;
	s->total = 0;
}

void	ps_record_op(t_ctx *ctx, t_op op)
{
	if (!ctx)
		return ;
	if (op < 0 || op >= 11)
		return ;
	ctx->stats.counts[op]++;
	ctx->stats.total++;
}

static void	print_strategy(const t_ctx *ctx)
{
	t_strategy	use;

	use = ctx->used;
	ps_write_str_fd("[bench] strategy: ", 2);
	ps_write_str_fd(ps_strategy_name(ctx->selected), 2);
	if (ctx->selected == STRAT_ADAPTIVE)
	{
		ps_write_str_fd(" -> ", 2);
		ps_write_str_fd(ps_strategy_name(use), 2);
	}
	ps_write_str_fd(" (", 2);
	ps_write_str_fd(ps_strategy_complexity(use), 2);
	ps_write_str_fd(")\n", 2);
}

static void	print_op_counts(const t_stats *s)
{
	const char	*names[11] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};
	int			i;

	i = 0;
	while (i < 11)
	{
		ps_write_str_fd("[bench] ", 2);
		ps_write_str_fd(names[i], 2);
		ps_write_str_fd(": ", 2);
		ps_write_int_fd(s->counts[i], 2);
		ps_write_str_fd("\n", 2);
		i++;
	}
}

void	ps_print_bench(const t_ctx *ctx)
{
	if (!ctx)
		return ;
	ps_write_str_fd("[bench] disorder: ", 2);
	ps_write_double2_fd(ctx->disorder * 100.0, 2);
	ps_write_str_fd("%\n", 2);
	print_strategy(ctx);
	ps_write_str_fd("[bench] total_ops: ", 2);
	ps_write_int_fd(ctx->stats.total, 2);
	ps_write_str_fd("\n", 2);
	print_op_counts(&ctx->stats);
}
