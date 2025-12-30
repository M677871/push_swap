/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/27                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_reset(t_stack *s)
{
	s->head = NULL;
	s->tail = NULL;
	s->size = 0;
}

t_node	*node_create(int value, int idx)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->idx = idx;
	n->next = NULL;
	n->prev = NULL;
	return (n);
}

int	stack_append_node(t_stack *s, t_node *n)
{
	if (!s || !n)
		return (0);
	if (s->size == 0)
	{
		s->head = n;
		s->tail = n;
	}
	else
	{
		n->prev = s->tail;
		s->tail->next = n;
		s->tail = n;
	}
	s->size++;
	return (1);
}
