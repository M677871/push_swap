/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 09:20:25 by miissa            #+#    #+#             */
/*   Updated: 2026/01/05 12:54:56 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	can_swap(t_stack *s)
{
	return (s && s->size >= 2);
}

static void	op_swap(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (!can_swap(s))
		return ;
	first = stack_pop_front(s);
	second = stack_pop_front(s);
	stack_push_front(s, first);
	stack_push_front(s, second);
}

void	sa(t_stack *a, t_ctx *ctx)
{
	op_swap(a);
	ps_emit_op(ctx, OP_SA);
}

void	sb(t_stack *b, t_ctx *ctx)
{
	op_swap(b);
	ps_emit_op(ctx, OP_SB);
}

void	ss(t_stack *a, t_stack *b, t_ctx *ctx)
{
	op_swap(a);
	op_swap(b);
	ps_emit_op(ctx, OP_SS);
}
