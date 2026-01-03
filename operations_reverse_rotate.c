/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 09:20:38 by miissa            #+#    #+#             */
/*   Updated: 2026/01/03 12:59:28 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *s)
{
	t_node	*tmp;

	if (!s || s->size == 1)
		return ;
	tmp = s->bottom;
	s->top->prev = tmp;
	tmp->next = s->top;
	s->bottom = s->bottom->prev;
	s->top = tmp;
	s->bottom->next = NULL;
	s->top->prev = NULL;
}

void	rra(t_stack *a, t_ctx *ctx)
{
	reverse_rotate(a);
	ps_emit_op(ctx, OP_RRA);
}

void	rrb(t_stack *b, t_ctx *ctx)
{
	reverse_rotate(b);
	ps_emit_op(ctx, OP_RRB);
}

void	rrr(t_stack *a, t_stack *b, t_ctx *ctx)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ps_emit_op(ctx, OP_RRR);
}
