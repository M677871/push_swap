/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 11:26:39 by miissa            #+#    #+#             */
/*   Updated: 2026/01/05 11:34:58 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted_asc(t_stack *s)
{
	t_node	*temp;

	if (!s || s->size == 1)
		return (1);
	temp = s->top;
	while (temp && temp->next)
	{
		if (temp->value >= temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	stack_free_all(t_stack *s)
{
	t_node	*current;
	t_node	*to_delete;

	current = s->top;
	while (current)
	{
		to_delete = current;
		current = current->next;
		free(to_delete);
		to_delete = NULL;
	}
	s->bottom = NULL;
	s->top = NULL;
	s->size = 0;
}

int	stack_pos_of_min_index(t_stack *a)
{
	t_node	*cur;
	int		min;
	int		pos;
	int		best;

	if (!a || a->size == 0)
		return (0);
	cur = a->top;
	min = cur->index;
	pos = 0;
	best = 0;
	while (cur)
	{
		if (cur->index < min)
		{
			min = cur->index;
			best = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (best);
}

int	stack_pos_of_max_index(t_stack *a)
{
	t_node	*cur;
	int		max;
	int		pos;
	int		best;

	if (!a || a->size == 0)
		return (0);
	cur = a->top;
	max = cur->index;
	pos = 0;
	best = 0;
	while (cur)
	{
		if (cur->index > max)
		{
			max = cur->index;
			best = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (best);
}

t_node	*stack_pop_back(t_stack *s)
{
	t_node	*n;

	if (!s || s->size == 0)
		return (NULL);
	n = s->bottom;
	s->bottom = n->prev;
	if (s->bottom)
		s->bottom->next = NULL;
	else
		s->top = NULL;
	n->next = NULL;
	n->prev = NULL;
	s->size--;
	return (n);
}
