/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/27                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free_all(t_stack *s)
{
	t_node	*cur;
	t_node	*nxt;

	if (!s)
		return ;
	cur = s->head;
	while (cur)
	{
		nxt = cur->next;
		free(cur);
		cur = nxt;
	}
	s->head = NULL;
	s->tail = NULL;
	s->size = 0;
}

int	stack_is_sorted_asc(t_stack *a)
{
	t_node	*cur;

	if (!a || a->size <= 1)
		return (1);
	cur = a->head;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	stack_pos_of_min_idx(t_stack *a)
{
	t_node	*cur;
	int		min;
	int		pos;
	int		best;

	if (!a || a->size == 0)
		return (0);
	cur = a->head;
	min = cur->idx;
	pos = 0;
	best = 0;
	while (cur)
	{
		if (cur->idx < min)
		{
			min = cur->idx;
			best = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (best);
}

int	stack_pos_of_max_idx(t_stack *a)
{
	t_node	*cur;
	int		max;
	int		pos;
	int		best;

	if (!a || a->size == 0)
		return (0);
	cur = a->head;
	max = cur->idx;
	pos = 0;
	best = 0;
	while (cur)
	{
		if (cur->idx > max)
		{
			max = cur->idx;
			best = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (best);
}
