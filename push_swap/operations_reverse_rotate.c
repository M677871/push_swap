/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/30                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	can_rev_rotate(t_stack *s)
{
	return (s && s->size > 1);
}

static void	op_rev_rotate(t_stack *s)
{
	t_node	*n;

	if (!can_rev_rotate(s))
		return ;
	n = stack_pop_back(s);
	stack_push_front(s, n);
}

void	rra(t_stack *a, t_ctx *ctx)
{
	op_rev_rotate(a);
	ps_emit_op(ctx, OP_RRA);
}

void	rrb(t_stack *b, t_ctx *ctx)
{
	op_rev_rotate(b);
	ps_emit_op(ctx, OP_RRB);
}

void	rrr(t_stack *a, t_stack *b, t_ctx *ctx)
{
	op_rev_rotate(a);
	op_rev_rotate(b);
	ps_emit_op(ctx, OP_RRR);
}
