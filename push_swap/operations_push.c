/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/27                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_push(t_stack *dst, t_stack *src)
{
	t_node	*n;

	if (!dst || !src || src->size == 0)
		return ;
	n = src->head;
	src->head = n->next;
	if (src->head)
		src->head->prev = NULL;
	else
		src->tail = NULL;
	src->size--;
	n->prev = NULL;
	n->next = dst->head;
	if (dst->head)
		dst->head->prev = n;
	else
		dst->tail = n;
	dst->head = n;
	dst->size++;
}

void	pa(t_stack *a, t_stack *b, t_ctx *ctx)
{
	op_push(a, b);
	ps_record_op(ctx, OP_PA);
	if (ctx && ctx->print_ops)
		ps_write_str_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b, t_ctx *ctx)
{
	op_push(b, a);
	ps_record_op(ctx, OP_PB);
	if (ctx && ctx->print_ops)
		ps_write_str_fd("pb\n", 1);
}
