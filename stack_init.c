/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 08:28:27 by miissa            #+#    #+#             */
/*   Updated: 2026/01/03 13:03:35 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

void	push(t_stack *s, t_node *n)
{
	if (!s || !n)
		return ;
	if (s->size == 0)
	{
		s->top = n;
		s->bottom = n;
	}
	else
	{
		s->top->prev = n;
		n->next = s->top;
		s->top = n;
	}
	s->size += 1;
}

t_node	*pop(t_stack *s)
{
	t_node	*pop;

	pop = s->top;
	if (pop->next)
	{
		s->top = pop->next;
		s->top->prev = NULL;
	}
	else
	{
		s->top = NULL;
		s->bottom = NULL;
	}
	pop->next = NULL;
	pop->prev = NULL;
	s->size--;
	return (pop);
}
