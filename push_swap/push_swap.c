/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/27                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_ctx	ctx;
	int		start;

	stack_reset(&a);
	stack_reset(&b);
	ps_ctx_init(&ctx, 1);
	if (argc <= 1)
		return (0);
	if (!ps_parse_flags(argc, argv, &ctx, &start))
		ps_exit_error(&a, &b, 1);
	if (start >= argc)
		return (0);
	if (!ps_build_stack_from_args(argc, argv, start, &a, &ctx.disorder))
		ps_exit_error(&a, &b, 1);
	ps_run_strategy(&a, &b, &ctx);
	if (ctx.bench)
		ps_print_bench(&ctx);
	stack_free_all(&a);
	stack_free_all(&b);
	return (0);
}
