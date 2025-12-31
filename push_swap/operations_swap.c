/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/30                                 ###   ########.fr       */
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
