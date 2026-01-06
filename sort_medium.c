/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 12:42:24 by miissa            #+#    #+#             */
/*   Updated: 2026/01/05 12:03:13 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	int_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
	{
		if (i * i == n)
			return (i);
		else if (i * i < n)
			i++;
	}
	return (i - 1);
}

static int	calculate_chunck(int n)
{
	int	chunck;

	chunck = int_sqrt(n);
	if (chunck < 1)
		chunck = 1;
	return (chunck);
}

static void	push_to_b_window(t_stack *a, t_stack *b, t_ctx *ctx, int *next,
		int chunck)
{
	if (a->top->index <= *next)
	{
		pb(a, b, ctx);
		rb(b, ctx);
		(*next)++;
	}
	else if (a->top->index < *next + chunck)
	{
		pb(a, b, ctx);
		(*next)++;
	}
	else
		ra(a, ctx);
}

static void	push_max_to_a(t_stack *a, t_stack *b, t_ctx *ctx)
{
	int	pos;

	pos = stack_pos_of_max_index(b);
	if (pos <= b->size / 2)
		while (pos-- > 0)
			rb(b, ctx);
	else
	{
		pos = b->size - pos;
		while (pos-- > 0)
			rrb(b, ctx);
	}
	pa(a, b, ctx);
}

void	sort_medium_using_chunk(t_stack *a, t_stack *b, t_ctx *ctx)
{
	int	chunck;
	int	next;

	if (a && a->size > 1 && !stack_is_sorted_asc(a))
	{
		chunck = calculate_chunck(a->size);
		next = 0;
		while (a->size > 0)
			push_to_b_window(a, b, ctx, &next, chunck);
		while (b->size > 0)
			push_max_to_a(a, b, ctx);
	}
}
