/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/27                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_swap(t_stack *s)
{
	t_node	*a;
	t_node	*b;

	if (!s || s->size < 2)
		return ;
	a = s->head;
	b = a->next;
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	b->prev = NULL;
	b->next = a;
	a->prev = b;
	s->head = b;
	if (s->tail == b)
		s->tail = a;
}

void	sa(t_stack *a, t_ctx *ctx)
{
	op_swap(a);
	ps_record_op(ctx, OP_SA);
	if (ctx && ctx->print_ops)
		ps_write_str_fd("sa\n", 1);
}

void	sb(t_stack *b, t_ctx *ctx)
{
	op_swap(b);
	ps_record_op(ctx, OP_SB);
	if (ctx && ctx->print_ops)
		ps_write_str_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b, t_ctx *ctx)
{
	op_swap(a);
	op_swap(b);
	ps_record_op(ctx, OP_SS);
	if (ctx && ctx->print_ops)
		ps_write_str_fd("ss\n", 1);
}
