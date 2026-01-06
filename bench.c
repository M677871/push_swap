/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:15:11 by miissa            #+#    #+#             */
/*   Updated: 2026/01/06 07:41:29 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(const t_ctx *ctx)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ps_putpercent2_fd(ctx->disorder * 100.0, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_strategy(const t_ctx *ctx)
{
	t_strategy	use;

	use = ctx->used;
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(ps_strategy_name(ctx->selected), 2);
	if (ctx->selected == START_ADAPTIVE)
	{
		ft_putstr_fd(" -> ", 2);
		ft_putstr_fd(ps_strategy_name(use), 2);
	}
	ft_putstr_fd(" (", 2);
	ft_putstr_fd(ps_strategy_complexity(use), 2);
	ft_putstr_fd(")\n", 2);
}

static void	print_total(const t_ctx *ctx)
{
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(ctx->stats.total, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_op_counts(const t_stats *s)
{
	const char	*names[11];
	int			i;

	i = 0;
	names[0] = "sa";
	names[1] = "sb";
	names[2] = "ss";
	names[3] = "pa";
	names[4] = "pb";
	names[5] = "ra";
	names[6] = "rb";
	names[7] = "rr";
	names[8] = "rra";
	names[9] = "rrb";
	names[10] = "rrr";
	while (i < 11)
	{
		ft_putstr_fd("[bench] ", 2);
		ft_putstr_fd(names[i], 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(s->count[i], 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
}

void	ps_print_bench(const t_ctx *ctx)
{
	if (ctx)
	{
		print_disorder(ctx);
		print_strategy(ctx);
		print_total(ctx);
		print_op_counts(&ctx->stats);
	}
}
