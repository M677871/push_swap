/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/27                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (a->head->next && a->head->idx > a->head->next->idx)
			sa(a, ctx);
		ra(a, ctx);
		i++;
	}
	while (i-- > 0)
		rra(a, ctx);
	return (stack_is_sorted_asc(a));
}

static t_strategy	pick_adaptive(double disorder)
{
	if (disorder < 0.2)
		return (STRAT_LOW);
	if (disorder < 0.5)
		return (STRAT_MEDIUM);
	return (STRAT_COMPLEX);
}

t_strategy	sort_adaptive(t_stack *a, t_stack *b, t_ctx *ctx)
{
	t_strategy	choice;

	choice = pick_adaptive(ctx->disorder);
	if (choice == STRAT_LOW)
	{
		if (low_pass(a, ctx))
			return (STRAT_LOW);
		sort_medium(a, b, ctx);
		return (STRAT_MEDIUM);
	}
	if (choice == STRAT_MEDIUM)
	{
		sort_medium(a, b, ctx);
		return (STRAT_MEDIUM);
	}
	sort_complex(a, b, ctx);
	return (STRAT_COMPLEX);
}
