/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 09:34:08 by miissa            #+#    #+#             */
/*   Updated: 2026/01/03 14:17:35 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	*ps_strategy_name(t_strategy s)
{
	if (s == START_SIMPLE)
		return ("simple");
	if (s == START_MEDIUM)
		return ("medium");
	if (s == START_COMPLEX)
		return ("complex");
	if (s == START_LOW)
		return ("adaptive_low");
	return ("adaptive");
}

const char	*ps_strategy_complexity(t_strategy s)
{
	if (s == START_SIMPLE)
		return ("O(n^2)");
	if (s == START_MEDIUM)
		return ("O(n*sqrt(n))");
	if (s == START_COMPLEX)
		return ("O(nlog(n))");
	if (s == START_LOW)
		return ("O(n)");
	return ("O(?)");
}

static void	run_forced(t_stack *a, t_stack *b, t_ctx *ctx)
{
	if (ctx->selected == START_SIMPLE)
	{
		ctx->used = START_SIMPLE;
		sort_simple_using_selection(a, b, ctx);
	}
	else if (ctx->selected == START_MEDIUM)
	{
		ctx->used = START_MEDIUM;
		sort_medium_using_chunk(a, b, ctx);
	}
	else if (ctx->selected == START_COMPLEX)
	{
		ctx->used = START_COMPLEX;
		sort_complex(a, b, ctx);
	}
	else if (ctx->selected == START_ADAPTIVE)
	{
		ctx->used = sort_adaptive(a, b, ctx);
	}
}

void	ps_run_strategy(t_stack *a, t_stack *b, t_ctx *ctx)
{
	if (a && b && ctx)
	{
		run_forced(a, b, ctx);
	}
}
