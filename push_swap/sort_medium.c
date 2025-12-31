/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/30                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	int_sqrt(int n)
{
	int	i;

	i = 0;
	while ((i + 1) * (i + 1) <= n)
		i++;
	return (i);
}

static int	calc_chunk(int n)
{
	int	chunk;

	chunk = int_sqrt(n);
	if (chunk < 1)
		chunk = 1;
	return (chunk);
}

static void	push_to_b_window(t_stack *a, t_stack *b, t_ctx *ctx,
		int *next, int chunk)
{
	if (a->head->idx <= *next)
	{
		pb(a, b, ctx);
		rb(b, ctx);
		(*next)++;
	}
	else if (a->head->idx < *next + chunk)
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

	pos = stack_pos_of_max_idx(b);
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

void	sort_medium(t_stack *a, t_stack *b, t_ctx *ctx)
{
	int	chunk;
	int	next;

	if (!a || a->size <= 1 || stack_is_sorted_asc(a))
		return ;
	chunk = calc_chunk(a->size);
	next = 0;
	while (a->size > 0)
		push_to_b_window(a, b, ctx, &next, chunk);
	while (b->size > 0)
		push_max_to_a(a, b, ctx);
}
