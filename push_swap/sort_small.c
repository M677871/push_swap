/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/27                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_min(t_stack *a, int pos, t_ctx *ctx)
{
	if (pos <= a->size / 2)
		while (pos-- > 0)
			ra(a, ctx);
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

	pos = stack_pos_of_min_idx(a);
	rotate_to_min(a, pos, ctx);
	pb(a, b, ctx);
}

void	sort_simple(t_stack *a, t_stack *b, t_ctx *ctx)
{
	if (!a || a->size <= 1 || stack_is_sorted_asc(a))
		return ;
	while (a->size > 0)
		push_min_to_b(a, b, ctx);
	while (b->size > 0)
		pa(a, b, ctx);
}
