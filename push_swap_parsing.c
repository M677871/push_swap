/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 07:21:16 by miissa            #+#    #+#             */
/*   Updated: 2026/01/06 09:57:34 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_values(const int *src, int n)
{
	int	*dst;

	dst = (int *)ft_calloc(n, sizeof(int));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, src, sizeof(int) * n);
	return (dst);
}

static int	find_index_sorted(const int *sorted, int n, int value)
{
	int	lo;
	int	hi;
	int	mid;

	lo = 0;
	hi = n - 1;
	while (lo <= hi)
	{
		mid = lo + (hi - lo) / 2;
		if (sorted[mid] == value)
			return (mid);
		if (sorted[mid] < value)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return (-1);
}

static int	prepare_sorted(int **sorted, const int *vals, int n)
{
	*sorted = copy_values(vals, n);
	if (!*sorted)
		return (0);
	if (!int_array_sort_asc(*sorted, n))
		return (free(*sorted), 0);
	if (int_array_has_duplicates_sorted(*sorted, n))
		return (free(*sorted), 0);
	return (1);
}

static int	fill_stack_from_values(t_stack *a, const int *vals,
		const int *sorted, int n)
{
	t_node	*node;
	int		i;
	int		idx;

	i = 0;
	while (i < n)
	{
		idx = find_index_sorted(sorted, n, vals[i]);
		node = node_create(vals[i], idx);
		if (idx < 0 || !node)
		{
			if (node)
				free(node);
			stack_free_all(a);
			return (0);
		}
		stack_push_back(a, node);
		i++;
	}
	return (1);
}

int	ps_build_stack_from_args(t_input *input, t_stack *a, double *out_disorder)
{
	int	*vals;
	int	*sorted;
	int	n;

	stack_reset(a);
	if (!ps_parse_argv_to_ints(input, &vals, &n))
		return (0);
	if (out_disorder)
		*out_disorder = ps_compute_disorder(vals, n);
	if (!prepare_sorted(&sorted, vals, n))
		return (free(vals), 0);
	if (!fill_stack_from_values(a, vals, sorted, n))
		return (free(sorted), free(vals), 0);
	free(sorted);
	free(vals);
	return (1);
}
