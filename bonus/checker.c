/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/27                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef void	(*t_op_exec)(t_stack *, t_stack *, t_ctx *);

static int	line_is_op(const char *line, const char *op)
{
	int	i;

	i = 0;
	while (line[i] && op[i] && line[i] == op[i])
		i++;
	if (op[i] != '\0')
		return (0);
	if (line[i] == '\n' && line[i + 1] == '\0')
		return (1);
	return (line[i] == '\0');
}

static void	op_sa(t_stack *a, t_stack *b, t_ctx *ctx)
{
	(void)b;
	sa(a, ctx);
}

static void	op_sb(t_stack *a, t_stack *b, t_ctx *ctx)
{
	(void)a;
	sb(b, ctx);
}

static void	op_ss(t_stack *a, t_stack *b, t_ctx *ctx)
{
	ss(a, b, ctx);
}

static void	op_pa(t_stack *a, t_stack *b, t_ctx *ctx)
{
	pa(a, b, ctx);
}

static void	op_pb(t_stack *a, t_stack *b, t_ctx *ctx)
{
	pb(a, b, ctx);
}

static void	op_ra(t_stack *a, t_stack *b, t_ctx *ctx)
{
	(void)b;
	ra(a, ctx);
}

static void	op_rb(t_stack *a, t_stack *b, t_ctx *ctx)
{
	(void)a;
	rb(b, ctx);
}

static void	op_rr(t_stack *a, t_stack *b, t_ctx *ctx)
{
	rr(a, b, ctx);
}

static void	op_rra(t_stack *a, t_stack *b, t_ctx *ctx)
{
	(void)b;
	rra(a, ctx);
}

static void	op_rrb(t_stack *a, t_stack *b, t_ctx *ctx)
{
	(void)a;
	rrb(b, ctx);
}

static void	op_rrr(t_stack *a, t_stack *b, t_ctx *ctx)
{
	rrr(a, b, ctx);
}

static int	exec_op(const char *line, t_stack *a, t_stack *b, t_ctx *ctx)
{
	const char	*ops[11] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};
	t_op_exec	fns[11] = {op_sa, op_sb, op_ss, op_pa, op_pb, op_ra,
		op_rb, op_rr, op_rra, op_rrb, op_rrr};
	int			i;

	i = 0;
	while (i < 11)
	{
		if (line_is_op(line, ops[i]))
		{
			fns[i](a, b, ctx);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	read_and_exec(t_stack *a, t_stack *b, t_ctx *ctx)
{
	char	*line;
	int		err;

	while (1)
	{
		line = ps_readline(0, &err);
		if (err)
			return (0);
		if (!line)
			break ;
		if (line[0] == '\n' || line[0] == '\0')
			return (free(line), 0);
		if (!exec_op(line, a, b, ctx))
			return (free(line), 0);
		free(line);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_ctx	ctx;

	stack_reset(&a);
	stack_reset(&b);
	ps_ctx_init(&ctx, 0);
	if (argc <= 1)
		return (0);
	if (!ps_build_stack_from_args(argc, argv, 1, &a, NULL))
		ps_exit_error(&a, &b, 1);
	if (!read_and_exec(&a, &b, &ctx))
		ps_exit_error(&a, &b, 1);
	if (stack_is_sorted_asc(&a) && b.size == 0)
		ps_write_str_fd("OK\n", 1);
	else
		ps_write_str_fd("KO\n", 1);
	stack_free_all(&a);
	stack_free_all(&b);
	return (0);
}
