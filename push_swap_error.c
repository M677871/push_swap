/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:56:31 by miissa            #+#    #+#             */
/*   Updated: 2026/01/03 13:00:14 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_stack(t_stack *s)
{
	if (s)
	{
		stack_free_all(s);
	}
}

static void	clear_ctx(t_ctx *ctx)
{
	if (ctx)
	{
		ctx->bench = 0;
		ctx->disorder = 0.0;
		ctx->selected = START_ADAPTIVE;
		ctx->used = START_ADAPTIVE;
		ps_stats_init(&ctx->stats);
	}
}

static void	write_error(void)
{
	ft_putendl_fd("Error", 2);
}

void	ps_cleanup(t_ctx *ctx, t_stack *a, t_stack *b)
{
	clear_stack(a);
	clear_stack(b);
	clear_ctx(ctx);
}

void	ps_exit_error(t_ctx *ctx, t_stack *a, t_stack *b, int code)
{
	ps_cleanup(ctx, a, b);
	write_error();
	exit(code);
}
