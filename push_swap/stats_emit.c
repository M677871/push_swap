/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats_emit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30                                 #+#    #+#             */
/*   Updated: 2025/12/30                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stats_init(t_stats *s)
{
	if (!s)
		return ;
	ft_bzero(s->counts, sizeof(s->counts));
	s->total = 0;
}

static const char	*op_name(t_op op)
{
	static const char	*names[11] = {
		"sa\n", "sb\n", "ss\n", "pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"
	};

	if (op < 0 || op > OP_RRR)
		return (NULL);
	return (names[op]);
}

static void	count_op(t_ctx *ctx, t_op op)
{
	if (!ctx || op < 0 || op > OP_RRR)
		return ;
	ctx->stats.counts[op]++;
	ctx->stats.total++;
}

static void	write_op(t_ctx *ctx, t_op op)
{
	const char	*name;

	if (!ctx || !ctx->print_ops)
		return ;
	name = op_name(op);
	if (name)
		ft_putstr_fd(name, 1);
}

void	ps_emit_op(t_ctx *ctx, t_op op)
{
	count_op(ctx, op);
	write_op(ctx, op);
}
