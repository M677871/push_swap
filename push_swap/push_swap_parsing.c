/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/27                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_values(const int *src, int n)
{
	int	*dst;
	int	i;

	dst = (int *)malloc(sizeof(int) * n);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

static int	fill_stack_from_values(t_stack *a, const int *vals,
		const int *sorted, int n)
{
	int		i;
	int		idx;
	t_node	*node;

	i = 0;
	while (i < n)
	{
		idx = int_array_find_index(sorted, n, vals[i]);
		node = node_create(vals[i], idx);
		if (!node || idx < 0 || !stack_append_node(a, node))
		{
			if (node)
				free(node);
			return (stack_free_all(a), 0);
		}
		i++;
	}
	return (1);
}

static int	prepare_sorted(int **sorted, int *vals, int n)
{
	*sorted = copy_values(vals, n);
	if (!*sorted)
		return (0);
	int_array_sort_asc(*sorted, n);
	if (int_array_has_duplicates_sorted(*sorted, n))
		return (free(*sorted), 0);
	return (1);
}

/*
** Build stack A with idx already assigned (rank in sorted array).
** Returns 1 ok, 0 error.
*/
int	ps_build_stack_from_args(int argc, char **argv, int start,
		t_stack *a, double *out_disorder)
{
	int	*vals;
	int	*sorted;
	int	n;

	stack_reset(a);
	if (start >= argc)
		return (1);
	if (!ps_parse_argv_to_ints(argc, argv, start, &vals, &n))
		return (0);
	if (n == 0)
		return (free(vals), 0);
	if (out_disorder)
		*out_disorder = ps_compute_disorder(vals, n);
	if (!prepare_sorted(&sorted, vals, n))
		return (free(vals), stack_free_all(a), 0);
	if (!fill_stack_from_values(a, vals, sorted, n))
		return (free(sorted), free(vals), 0);
	free(sorted);
	free(vals);
	return (1);
}
