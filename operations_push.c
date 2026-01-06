/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:27:59 by miissa            #+#    #+#             */
/*   Updated: 2026/01/05 13:07:42 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	can_push(t_stack *s)
{
	return (s && s->size > 0);
}

static t_node	*take_node(t_stack *s)
{
	if (!can_push(s))
		return (NULL);
	return (stack_pop_front(s));
}

static void	op_push(t_stack *src, t_stack *dest)
{
	t_node	*temp;

	temp = take_node(src);
	if (!temp)
		return ;
	stack_push_front(dest, temp);
}

void	pa(t_stack *a, t_stack *b, t_ctx *ctx)
{
	op_push(b, a);
	ps_emit_op(ctx, OP_PA);
}

void	pb(t_stack *a, t_stack *b, t_ctx *ctx)
{
	op_push(a, b);
	ps_emit_op(ctx, OP_PB);
}
