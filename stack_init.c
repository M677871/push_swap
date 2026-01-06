/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 08:28:27 by miissa            #+#    #+#             */
/*   Updated: 2026/01/05 13:20:13 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_reset(t_stack *s)
{
	s->bottom = NULL;
	s->top = NULL;
	s->size = 0;
}

t_node	*node_create(int value, int index)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->index = index;
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	stack_push_front(t_stack *s, t_node *n)
{
	if (!s || !n)
		return ;
	n->prev = NULL;
	n->next = s->top;
	if (s->top)
		s->top->prev = n;
	else
		s->bottom = n;
	s->top = n;
	s->size++;
}

void	stack_push_back(t_stack *s, t_node *n)
{
	if (!s || !n)
		return ;
	n->next = NULL;
	n->prev = s->bottom;
	if (s->bottom)
		s->bottom->next = n;
	else
		s->top = n;
	s->bottom = n;
	s->size++;
}

t_node	*stack_pop_front(t_stack *s)
{
	t_node	*n;

	if (!s || s->size == 0)
		return (NULL);
	n = s->top;
	s->top = n->next;
	if (s->top)
		s->top->prev = NULL;
	else
		s->bottom = NULL;
	n->next = NULL;
	n->prev = NULL;
	s->size--;
	return (n);
}
