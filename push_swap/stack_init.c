/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/30                                 ###   ########.fr       */
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

void	stack_push_front(t_stack *s, t_node *n)
{
	if (!s || !n)
		return ;
	n->prev = NULL;
	n->next = s->head;
	if (s->head)
		s->head->prev = n;
	else
		s->tail = n;
	s->head = n;
	s->size++;
}

void	stack_push_back(t_stack *s, t_node *n)
{
	if (!s || !n)
		return ;
	n->next = NULL;
	n->prev = s->tail;
	if (s->tail)
		s->tail->next = n;
	else
		s->head = n;
	s->tail = n;
	s->size++;
}

t_node	*stack_pop_front(t_stack *s)
{
	t_node	*n;

	if (!s || s->size == 0)
		return (NULL);
	n = s->head;
	s->head = n->next;
	if (s->head)
		s->head->prev = NULL;
	else
		s->tail = NULL;
	n->next = NULL;
	n->prev = NULL;
	s->size--;
	return (n);
}
