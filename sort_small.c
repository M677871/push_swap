/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 10:00:00 by miissa            #+#    #+#             */
/*   Updated: 2026/02/22 10:00:00 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_stack(t_stack *a, t_ctx *ctx)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->value;
	mid = a->top->next->value;
	bot = a->top->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(a, ctx);
	else if (top > mid && mid > bot)
	{
		sa(a, ctx);
		rra(a, ctx);
	}
	else if (top > mid)
		ra(a, ctx);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a, ctx);
		ra(a, ctx);
	}
	else if (top < mid && mid > bot)
		rra(a, ctx);
}

void	sort_small_stack(t_stack *a, t_ctx *ctx)
{
	if (!a || a->size <= 1 || stack_is_sorted_asc(a))
		return ;
	if (a->size == 2)
	{
		sa(a, ctx);
		return ;
	}
	if (a->size == 3)
		sort_three_stack(a, ctx);
}
