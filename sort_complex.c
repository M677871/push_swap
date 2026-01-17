/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 12:42:32 by miissa            #+#    #+#             */
/*   Updated: 2026/01/06 10:42:04 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	need_sort(t_stack *a)
{
	if (!a || a->size <= 1)
		return (0);
	return (!stack_is_sorted_asc(a));
}

static int	max_bits(t_stack *a)
{
	int		max;
	int		bits;
	t_node	*cur;

	max = 0;
	cur = a->top;
	while (cur)
	{
		if (cur->index > max)
			max = cur->index;
		cur = cur->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	radix_pass(t_stack *a, t_stack *b, t_ctx *ctx, int bit)
{
	int	i;
	int	n;

	n = a->size;
	i = 0;
	while (i < n)
	{
		if (((a->top->index >> bit) & 1) == 0)
			pb(a, b, ctx);
		else
			ra(a, ctx);
		i++;
	}
	while (b->size > 0)
		pa(a, b, ctx);
}

static void	radix_sort(t_stack *a, t_stack *b, t_ctx *ctx)
{
	int	bit;
	int	mb;

	mb = max_bits(a);
	bit = 0;
	while (bit < mb)
	{
		radix_pass(a, b, ctx, bit);
		bit++;
	}
}

void	sort_complex(t_stack *a, t_stack *b, t_ctx *ctx)
{
	if (!need_sort(a))
		return ;
	radix_sort(a, b, ctx);
}
