/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/27                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(t_stack *a)
{
	int		max;
	int		bits;
	t_node	*cur;

	max = 0;
	cur = a->head;
	while (cur)
	{
		if (cur->idx > max)
			max = cur->idx;
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
		if (((a->head->idx >> bit) & 1) == 0)
			pb(a, b, ctx);
		else
			ra(a, ctx);
		i++;
	}
	while (b->size > 0)
		pa(a, b, ctx);
}

void	sort_complex(t_stack *a, t_stack *b, t_ctx *ctx)
{
	int	bit;
	int	mb;

	if (!a || a->size <= 1 || stack_is_sorted_asc(a))
		return ;
	mb = max_bits(a);
	bit = 0;
	while (bit < mb)
	{
		radix_pass(a, b, ctx, bit);
		bit++;
	}
}
