/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats_emit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 08:12:57 by miissa            #+#    #+#             */
/*   Updated: 2026/01/03 14:13:03 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*op_name(t_op op)
{
	static const char	*names[11];

	names[0] = "sa\n";
	names[1] = "sb\n";
	names[2] = "ss\n";
	names[3] = "pa\n";
	names[4] = "pb\n";
	names[5] = "ra\n";
	names[6] = "rb\n";
	names[7] = "rr\n";
	names[8] = "rra\n";
	names[9] = "rrb\n";
	names[10] = "rrr\n";
	if (op < 0 || op > OP_RRR)
		return (NULL);
	return (names[op]);
}

static void	count_op(t_ctx *ctx, t_op op)
{
	if (ctx && (op >= 0 && op <= OP_RRR))
	{
		ctx->stats.count[op]++;
		ctx->stats.total++;
	}
}

static void	write_op(t_ctx *ctx, t_op op)
{
	const char	*name;

	if (ctx && ctx->print_ops)
	{
		name = op_name(op);
		if (name)
			ft_putstr_fd(name, 1);
	}
}

void	ps_stats_init(t_stats *s)
{
	if (s)
	{
		ft_bzero(s->count, sizeof(s->count));
		s->total = 0;
	}
}

void	ps_emit_op(t_ctx *ctx, t_op op)
{
	count_op(ctx, op);
	write_op(ctx, op);
}
