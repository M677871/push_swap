/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/27                                 ###   ########.fr       */
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

static void	step_swap(int *arr, int *i, int *j)
{
	swap_int(&arr[*i], &arr[*j]);
	(*i)++;
	(*j)--;
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
			step_swap(arr, &i, &j);
	}
	if (left < j)
		quicksort_ints(arr, left, j);
	if (i < right)
		quicksort_ints(arr, i, right);
}

void	int_array_sort_asc(int *arr, int n)
{
	if (n > 1)
		quicksort_ints(arr, 0, n - 1);
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

int	int_array_find_index(const int *sorted, int n, int value)
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
