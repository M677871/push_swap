/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/30                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	can_push(t_stack *src)
{
	return (src && src->size > 0);
}

static t_node	*take_node(t_stack *src)
{
	if (!can_push(src))
		return (NULL);
	return (stack_pop_front(src));
}

static void	op_push(t_stack *dst, t_stack *src)
{
	t_node	*n;

	n = take_node(src);
	if (!n)
		return ;
	stack_push_front(dst, n);
}

void	pa(t_stack *a, t_stack *b, t_ctx *ctx)
{
	op_push(a, b);
	ps_emit_op(ctx, OP_PA);
}

void	pb(t_stack *a, t_stack *b, t_ctx *ctx)
{
	op_push(b, a);
	ps_emit_op(ctx, OP_PB);
}
