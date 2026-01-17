/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrad <rmrad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 12:42:20 by miissa            #+#    #+#             */
/*   Updated: 2026/01/12 12:07:43 by rmrad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_strategy	pick_adaptive(double disorder)
{
	if (disorder < 0.2)
		return (START_LOW);
	if (disorder < 0.5)
		return (START_MEDIUM);
	return (START_COMPLEX);
}

static int	low_pass(t_stack *a, t_ctx *ctx)
{
	int	i;
	int	n;

	if (!a || a->size <= 1 || stack_is_sorted_asc(a))
		return (1);
	n = a->size;
	i = 0;
	while (i < n)
	{
		if (a->top->next && a->top->index > a->top->next->index)
			sa(a, ctx);
		else
			ra(a, ctx);
		i++;
	}
	while (i-- > 1)
		rra(a, ctx);
	return (stack_is_sorted_asc(a));
}

static t_strategy	run_low(t_stack *a, t_stack *b, t_ctx *ctx)
{
	if (low_pass(a, ctx))
		return (START_LOW);
	sort_medium_using_chunk(a, b, ctx);
	return (START_MEDIUM);
}

static t_strategy	run_choice(t_stack *a, t_stack *b, t_ctx *ctx,
		t_strategy choice)
{
	if (choice == START_MEDIUM)
	{
		sort_medium_using_chunk(a, b, ctx);
		return (START_MEDIUM);
	}
	sort_complex(a, b, ctx);
	return (START_COMPLEX);
}

t_strategy	sort_adaptive(t_stack *a, t_stack *b, t_ctx *ctx)
{
	t_strategy	choice;

	choice = pick_adaptive(ctx->disorder);
	if (choice == START_LOW)
		return (run_low(a, b, ctx));
	return (run_choice(a, b, ctx, choice));
}
