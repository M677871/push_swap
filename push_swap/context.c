/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/27                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ctx_init(t_ctx *ctx, int print_ops)
{
	if (!ctx)
		return ;
	ctx->print_ops = print_ops;
	ctx->bench = 0;
	ctx->disorder = 0.0;
	ctx->selected = STRAT_ADAPTIVE;
	ctx->used = STRAT_ADAPTIVE;
	ps_stats_init(&ctx->stats);
}

static int	set_strategy(t_ctx *ctx, int *set, t_strategy strat)
{
	if (*set)
		return (0);
	ctx->selected = strat;
	*set = 1;
	return (1);
}

static int	handle_flag(const char *arg, t_ctx *ctx, int *set)
{
	if (ps_streq(arg, "--bench"))
	{
		ctx->bench = 1;
		return (1);
	}
	if (ps_streq(arg, "--simple"))
		return (set_strategy(ctx, set, STRAT_SIMPLE) ? 1 : -1);
	if (ps_streq(arg, "--medium"))
		return (set_strategy(ctx, set, STRAT_MEDIUM) ? 1 : -1);
	if (ps_streq(arg, "--complex"))
		return (set_strategy(ctx, set, STRAT_COMPLEX) ? 1 : -1);
	if (ps_streq(arg, "--adaptive"))
		return (set_strategy(ctx, set, STRAT_ADAPTIVE) ? 1 : -1);
	return (0);
}

int	ps_parse_flags(int argc, char **argv, t_ctx *ctx, int *out_start)
{
	int	i;
	int	set;

	i = 1;
	set = 0;
	while (i < argc)
	{
		int	r;

		r = handle_flag(argv[i], ctx, &set);
		if (r == 0)
			break ;
		if (r < 0)
			return (0);
		i++;
	}
	*out_start = i;
	return (1);
}
