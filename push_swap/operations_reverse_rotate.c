/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/27                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_rev_rotate(t_stack *s)
{
	t_node	*n;

	if (!s || s->size < 2)
		return ;
	n = s->tail;
	s->tail = n->prev;
	s->tail->next = NULL;
	n->prev = NULL;
	n->next = s->head;
	s->head->prev = n;
	s->head = n;
}

void	rra(t_stack *a, t_ctx *ctx)
{
	op_rev_rotate(a);
	ps_record_op(ctx, OP_RRA);
	if (ctx && ctx->print_ops)
		ps_write_str_fd("rra\n", 1);
}

void	rrb(t_stack *b, t_ctx *ctx)
{
	op_rev_rotate(b);
	ps_record_op(ctx, OP_RRB);
	if (ctx && ctx->print_ops)
		ps_write_str_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b, t_ctx *ctx)
{
	op_rev_rotate(a);
	op_rev_rotate(b);
	ps_record_op(ctx, OP_RRR);
	if (ctx && ctx->print_ops)
		ps_write_str_fd("rrr\n", 1);
}
