/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 07:40:04 by miissa            #+#    #+#             */
/*   Updated: 2026/01/06 09:58:15 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	grow_vals(int **vals, int *cap, int n)
{
	int	newcap;
	int	*tmp;

	if (*cap == 0)
		newcap = 16;
	else
		newcap = *cap * 2;
	while (newcap < n)
		newcap *= 2;
	tmp = (int *)ft_calloc(newcap, sizeof(int));
	if (!tmp)
		return (0);
	if (*vals)
		ft_memcpy(tmp, *vals, sizeof(int) * (*cap));
	free(*vals);
	*vals = tmp;
	*cap = newcap;
	return (1);
}

static int	append_val(int **vals, int *n, int *cap, int val)
{
	if (*n + 1 > *cap && !grow_vals(vals, cap, *n + 1))
		return (0);
	(*vals)[(*n)++] = val;
	return (1);
}

static int	parse_parts(char **parts, int **vals, int *n, int *cap)
{
	int	i;
	int	val;

	i = 0;
	while (parts[i])
	{
		if (!ps_parse_token(parts[i], &val))
			return (0);
		if (!append_val(vals, n, cap, val))
			return (0);
		i++;
	}
	return (1);
}

static int	parse_arg(const char *arg, int **vals, int *n, int *cap)
{
	char	**parts;
	int		ok;

	if (!arg || arg[0] == '\0')
		return (0);
	parts = ps_split_ws(arg);
	if (!parts)
		return (0);
	ok = parse_parts(parts, vals, n, cap);
	ps_free_split(parts);
	return (ok);
}

int	ps_parse_argv_to_ints(t_input *input, int **out_vals, int *out_n)
{
	int	*vals;
	int	cap;
	int	n;
	int	i;

	vals = NULL;
	cap = 0;
	n = 0;
	i = input->start;
	while (i < input->argc)
	{
		if (!parse_arg(input->argv[i], &vals, &n, &cap))
			return (free(vals), 0);
		i++;
	}
	if (n == 0)
		return (free(vals), 0);
	*out_vals = vals;
	*out_n = n;
	return (1);
}
