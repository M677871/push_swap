/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/27                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_rotate(t_stack *s)
{
	t_node	*n;

	if (!s || s->size < 2)
		return ;
	n = s->head;
	s->head = n->next;
	s->head->prev = NULL;
	n->next = NULL;
	n->prev = s->tail;
	s->tail->next = n;
	s->tail = n;
}

void	ra(t_stack *a, t_ctx *ctx)
{
	op_rotate(a);
	ps_record_op(ctx, OP_RA);
	if (ctx && ctx->print_ops)
		ps_write_str_fd("ra\n", 1);
}

void	rb(t_stack *b, t_ctx *ctx)
{
	op_rotate(b);
	ps_record_op(ctx, OP_RB);
	if (ctx && ctx->print_ops)
		ps_write_str_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b, t_ctx *ctx)
{
	op_rotate(a);
	op_rotate(b);
	ps_record_op(ctx, OP_RR);
	if (ctx && ctx->print_ops)
		ps_write_str_fd("rr\n", 1);
}
