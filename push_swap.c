/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:14:09 by miissa            #+#    #+#             */
/*   Updated: 2026/01/06 10:47:23 by miissa           ###   ########.fr       */
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

static int	build_stack_or_error(t_input *input, t_stack *a, t_ctx *ctx)
{
	if (input->start >= input->argc)
		return (0);
	if (!ps_build_stack_from_args(input, a, &ctx->disorder))
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
	int		r;
	t_input	input;

	input_init(&input);
	input.argc = argc;
	input.argv = argv;
	input.start = 0;
	init_all(&a, &b, &ctx);
	r = parse_flags_or_error(input.argc, input.argv, &ctx, &input.start);
	if (r < 0)
		ps_exit_error(&ctx, &a, &b, 1);
	if (r == 0)
		return (0);
	r = build_stack_or_error(&input, &a, &ctx);
	if (r < 0)
		ps_exit_error(&ctx, &a, &b, 1);
	if (r > 0)
		run_all(&a, &b, &ctx);
	ps_cleanup(&ctx, &a, &b);
	return (0);
}
