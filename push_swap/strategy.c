/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/30                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	*ps_strategy_name(t_strategy s)
{
	if (s == STRAT_SIMPLE)
		return ("simple");
	if (s == STRAT_MEDIUM)
		return ("medium");
	if (s == STRAT_COMPLEX)
		return ("complex");
	if (s == STRAT_LOW)
		return ("adaptive-low");
	return ("adaptive");
}

const char	*ps_strategy_complexity(t_strategy s)
{
	if (s == STRAT_SIMPLE)
		return ("O(n^2)");
	if (s == STRAT_MEDIUM)
		return ("O(n*sqrt(n))");
	if (s == STRAT_COMPLEX)
		return ("O(n log n)");
	if (s == STRAT_LOW)
		return ("O(n)");
	return ("O(?)");
}

static void	run_forced(t_stack *a, t_stack *b, t_ctx *ctx)
{
	if (ctx->selected == STRAT_SIMPLE)
	{
		ctx->used = STRAT_SIMPLE;
		sort_simple(a, b, ctx);
	}
	else if (ctx->selected == STRAT_MEDIUM)
	{
		ctx->used = STRAT_MEDIUM;
		sort_medium(a, b, ctx);
	}
	else if (ctx->selected == STRAT_COMPLEX)
	{
		ctx->used = STRAT_COMPLEX;
		sort_complex(a, b, ctx);
	}
}

static void	run_adaptive(t_stack *a, t_stack *b, t_ctx *ctx)
{
	ctx->used = sort_adaptive(a, b, ctx);
}

void	ps_run_strategy(t_stack *a, t_stack *b, t_ctx *ctx)
{
	if (!a || !b || !ctx)
		return ;
	if (ctx->selected == STRAT_ADAPTIVE)
		run_adaptive(a, b, ctx);
	else
		run_forced(a, b, ctx);
}
