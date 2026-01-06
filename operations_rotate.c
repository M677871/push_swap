/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:49:49 by miissa            #+#    #+#             */
/*   Updated: 2026/01/05 11:27:43 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	can_rotate(t_stack *s)
{
	return (s && s->size > 1);
}

static void	op_rotate(t_stack *s)
{
	t_node	*n;

	if (!can_rotate(s))
		return ;
	n = stack_pop_front(s);
	stack_push_back(s, n);
}

void	ra(t_stack *a, t_ctx *ctx)
{
	op_rotate(a);
	ps_emit_op(ctx, OP_RA);
}

void	rb(t_stack *b, t_ctx *ctx)
{
	op_rotate(b);
	ps_emit_op(ctx, OP_RB);
}

void	rr(t_stack *a, t_stack *b, t_ctx *ctx)
{
	op_rotate(a);
	op_rotate(b);
	ps_emit_op(ctx, OP_RR);
}
