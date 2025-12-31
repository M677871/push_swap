/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/30                                 ###   ########.fr       */
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

static int	is_flag(const char *arg)
{
	return (arg && arg[0] == '-' && arg[1] == '-');
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
	if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		ctx->bench = 1;
		return (1);
	}
	if (ft_strncmp(arg, "--simple", 9) == 0)
		return (set_strategy(ctx, set, STRAT_SIMPLE) ? 1 : -1);
	if (ft_strncmp(arg, "--medium", 9) == 0)
		return (set_strategy(ctx, set, STRAT_MEDIUM) ? 1 : -1);
	if (ft_strncmp(arg, "--complex", 10) == 0)
		return (set_strategy(ctx, set, STRAT_COMPLEX) ? 1 : -1);
	if (ft_strncmp(arg, "--adaptive", 11) == 0)
		return (set_strategy(ctx, set, STRAT_ADAPTIVE) ? 1 : -1);
	return (0);
}

int	ps_parse_flags(int argc, char **argv, t_ctx *ctx, int *out_start)
{
	int	i;
	int	set;
	int	r;

	i = 1;
	set = 0;
	while (i < argc && is_flag(argv[i]))
	{
		r = handle_flag(argv[i], ctx, &set);
		if (r <= 0)
			return (0);
		i++;
	}
	*out_start = i;
	return (1);
}
