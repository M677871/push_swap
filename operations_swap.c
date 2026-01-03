/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 09:20:25 by miissa            #+#    #+#             */
/*   Updated: 2026/01/03 12:59:45 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_first(t_stack *s)
{
	t_node	*tmp;

	if (!s || s->size == 1)
		return ;
	if (s->size == 2)
	{
		tmp = s->top;
		s->top = s->bottom;
		s->bottom = tmp;
		s->top->next = s->bottom;
		s->top->prev = NULL;
		s->bottom->next = NULL;
		s->bottom->prev = s->top;
		return ;
	}
	tmp = s->top->next;
	s->top->next = s->top->next->next;
	s->top->next->prev = s->top;
	tmp->next = s->top;
	tmp->prev = NULL;
	s->top = tmp;
	return ;
}

void	sa(t_stack *a, t_ctx *ctx)
{
	swap_first(a);
	ps_emit_op(ctx, OP_SA);
}

void	sb(t_stack *a, t_ctx *ctx)
{
	swap_first(a);
	ps_emit_op(ctx, OP_SB);
}

void	ss(t_stack *a, t_stack *b, t_ctx *ctx)
{
	swap_first(a);
	swap_first(b);
	ps_emit_op(ctx, OP_SS);
}
