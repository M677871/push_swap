/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:54:47 by miissa            #+#    #+#             */
/*   Updated: 2025/12/31 08:12:24 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	quicksort_ints(int *arr, int left, int right)
{
	int	i;
	int	j;
	int	pivot;

	i = left;
	j = right;
	pivot = arr[left + (right - left) / 2];
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
			swap_int(&arr[i++], &arr[j--]);
	}
	if (left < j)
		quicksort_ints(arr, left, j);
	if (i < right)
		quicksort_ints(arr, i, right);
}

int	int_array_sort_asc(int *arr, int n)
{
	if (!arr || n < 2)
		return (0);
	quicksort_ints(arr, 0, n - 1);
	return (1);
}

int	int_array_has_duplicates_sorted(const int *sorted, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		if (sorted[i] == sorted[i - 1])
			return (1);
		i++;
	}
	return (0);
}

double	ps_compute_disorder(const int *vals, int n)
{
	long	mistakes;
	long	total;
	int		i;
	int		j;

	if (!vals || n < 2)
		return (0.0);
	mistakes = 0;
	total = 0;
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (vals[i] > vals[j])
				mistakes++;
			total++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / (double)total);
}
