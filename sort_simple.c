/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 08:04:20 by miissa            #+#    #+#             */
/*   Updated: 2026/01/03 14:24:38 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	need_sort(t_stack *a)
{
	if (!a || a->size < 2)
		return (0);
	return (!stack_is_sorted_asc(a));
}

static void	rotate_to_pos(t_stack *a, int pos, t_ctx *ctx)
{
	if (pos < a->size / 2)
	{
		while (pos-- > 0)
			ra(a, ctx);
	}
	else
	{
		pos = a->size - pos;
		while (pos-- > 0)
			rra(a, ctx);
	}
}

static void	push_min_to_b(t_stack *a, t_stack *b, t_ctx *ctx)
{
	int	pos;

	pos = stack_pos_of_min_index(a);
	rotate_to_pos(a, pos, ctx);
	pb(a, b, ctx);
}

static void	push_all_back(t_stack *a, t_stack *b, t_ctx *ctx)
{
	while (b->size > 0)
		pa(a, b, ctx);
}

void	sort_simple_using_selection(t_stack *a, t_stack *b, t_ctx *ctx)
{
	if (need_sort(a))
	{
		while (a->size > 0)
			push_min_to_b(a, b, ctx);
		push_all_back(a, b, ctx);
	}
}
