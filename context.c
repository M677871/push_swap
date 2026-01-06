/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 08:06:22 by miissa            #+#    #+#             */
/*   Updated: 2026/01/05 13:00:02 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_flag(const char *arr)
{
	return (arr && arr[0] == '-' && arr[1] == '-');
}

void	ps_ctx_init(t_ctx *ctx, int print_ops)
{
	if (ctx)
	{
		ctx->print_ops = print_ops;
		ctx->bench = 0;
		ctx->disorder = 0.0;
		ctx->selected = START_ADAPTIVE;
		ctx->used = START_ADAPTIVE;
		ps_stats_init(&ctx->stats);
	}
}

static int	set_strategy(t_ctx *ctx, int *set, t_strategy strategy)
{
	if (*set)
		return (0);
	ctx->selected = strategy;
	*set = 1;
	return (1);
}

static int	handle_flag(const char *arr, t_ctx *ctx, int *set)
{
	if (ft_strncmp(arr, "--bench", 8) == 0)
	{
		ctx->bench = 1;
		return (1);
	}
	if (ft_strncmp(arr, "--simple", 9) == 0)
		return (set_strategy(ctx, set, START_SIMPLE));
	if (ft_strncmp(arr, "--medium", 9) == 0)
		return (set_strategy(ctx, set, START_MEDIUM));
	if (ft_strncmp(arr, "--complex", 10) == 0)
		return (set_strategy(ctx, set, START_COMPLEX));
	if (ft_strncmp(arr, "--adaptive", 9) == 0)
		return (set_strategy(ctx, set, START_ADAPTIVE));
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
