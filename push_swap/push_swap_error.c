/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/30                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_stack(t_stack *s)
{
	if (s)
		stack_free_all(s);
}

static void	clear_ctx(t_ctx *ctx)
{
	if (!ctx)
		return ;
	ctx->bench = 0;
	ctx->disorder = 0.0;
	ctx->selected = STRAT_ADAPTIVE;
	ctx->used = STRAT_ADAPTIVE;
	ps_stats_init(&ctx->stats);
}

void	ps_cleanup(t_ctx *ctx, t_stack *a, t_stack *b)
{
	clear_stack(a);
	clear_stack(b);
	clear_ctx(ctx);
}

static void	write_error(void)
{
	ft_putendl_fd("Error", 2);
}

void	ps_exit_error(t_ctx *ctx, t_stack *a, t_stack *b, int code)
{
	ps_cleanup(ctx, a, b);
	write_error();
	exit(code);
}
