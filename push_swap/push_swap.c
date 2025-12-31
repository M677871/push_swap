/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/30                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_all(t_stack *a, t_stack *b, t_ctx *ctx)
{
	stack_reset(a);
	stack_reset(b);
	ps_ctx_init(ctx, 1);
}

static int	parse_flags_or_error(int argc, char **argv, t_ctx *ctx, int *start)
{
	if (argc <= 1)
		return (0);
	if (!ps_parse_flags(argc, argv, ctx, start))
		return (-1);
	return (1);
}

static int	build_stack_or_error(int argc, char **argv, int start,
		t_stack *a, t_ctx *ctx)
{
	if (start >= argc)
		return (0);
	if (!ps_build_stack_from_args(argc, argv, start, a, &ctx->disorder))
		return (-1);
	return (1);
}

static void	run_all(t_stack *a, t_stack *b, t_ctx *ctx)
{
	ps_run_strategy(a, b, ctx);
	if (ctx->bench)
		ps_print_bench(ctx);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_ctx	ctx;
	int		start;
	int		r;

	init_all(&a, &b, &ctx);
	r = parse_flags_or_error(argc, argv, &ctx, &start);
	if (r < 0)
		ps_exit_error(&ctx, &a, &b, 1);
	if (r == 0)
		return (0);
	r = build_stack_or_error(argc, argv, start, &a, &ctx);
	if (r < 0)
		ps_exit_error(&ctx, &a, &b, 1);
	if (r > 0)
		run_all(&a, &b, &ctx);
	ps_cleanup(&ctx, &a, &b);
	return (0);
}
