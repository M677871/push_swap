/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:49:49 by miissa            #+#    #+#             */
/*   Updated: 2026/01/03 12:59:34 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *s)
{
	t_node	*temp;

	temp = s->top;
	s->top = temp->next;
	s->top->prev = NULL;
	s->bottom->next = temp;
	temp->prev = s->bottom;
	temp->next = NULL;
	s->bottom = temp;
}

void	ra(t_stack *a, t_ctx *ctx)
{
	rotate(a);
	ps_emit_op(ctx, OP_RA);
}

void	rb(t_stack *b, t_ctx *ctx)
{
	rotate(b);
	ps_emit_op(ctx, OP_RB);
}

void	rr(t_stack *a, t_stack *b, t_ctx *ctx)
{
	rotate(a);
	rotate(b);
	ps_emit_op(ctx, OP_RR);
}
