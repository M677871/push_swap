/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/27                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** One exit point for errors => prevents leaks.
** code: usually 1
*/
void	ps_exit_error(t_stack *a, t_stack *b, int code)
{
	if (a)
		stack_free_all(a);
	if (b)
		stack_free_all(b);
	ps_write_str_fd("Error\n", 2);
	exit(code);
}
