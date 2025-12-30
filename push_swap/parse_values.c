/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/27                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	skip_ws(const char *s, int *j)
{
	while (s[*j] && ps_is_whitespace(s[*j]))
		(*j)++;
	return (s[*j] != '\0');
}

static void	read_sign(const char *s, int *j, int *sign)
{
	*sign = 1;
	if (s[*j] == '+' || s[*j] == '-')
	{
		if (s[*j] == '-')
			*sign = -1;
		(*j)++;
	}
}

static int	read_digits(const char *s, int *j, long *num, int sign)
{
	if (s[*j] < '0' || s[*j] > '9')
		return (0);
	*num = 0;
	while (s[*j] >= '0' && s[*j] <= '9')
	{
		*num = *num * 10 + (s[*j] - '0');
		if (sign == 1 && *num > INT_MAX)
			return (0);
		if (sign == -1 && -*num < INT_MIN)
			return (0);
		(*j)++;
	}
	return (1);
}

/*
** Parse one integer token from s starting at *j.
** Returns: 1 on success, 0 on invalid token, 2 when no token is found.
*/
static int	parse_token_int(const char *s, int *j, int *out)
{
	int		sign;
	long	num;

	if (!skip_ws(s, j))
		return (2);
	read_sign(s, j, &sign);
	if (!read_digits(s, j, &num, sign))
		return (0);
	if (s[*j] && !ps_is_whitespace(s[*j]))
		return (0);
	*out = (int)(sign * num);
	return (1);
}

static int	grow_int_array(int **vals, int *cap)
{
	int	*nv;
	int	i;
	int	ncap;

	ncap = (*cap == 0) ? 32 : (*cap * 2);
	nv = (int *)malloc(sizeof(int) * ncap);
	if (!nv)
		return (0);
	i = 0;
	while (i < *cap)
	{
		nv[i] = (*vals)[i];
		i++;
	}
	free(*vals);
	*vals = nv;
	*cap = ncap;
	return (1);
}

static int	append_val(int **vals, int *n, int *cap, int val)
{
	if (*n == *cap && !grow_int_array(vals, cap))
		return (0);
	(*vals)[(*n)++] = val;
	return (1);
}

static int	parse_arg_tokens(const char *s, int **vals, int *n, int *cap)
{
	int	j;
	int	found;

	if (!s || s[0] == '\0')
		return (0);
	j = 0;
	found = 0;
	while (1)
	{
		int	val;
		int	r;

		r = parse_token_int(s, &j, &val);
		if (r == 2)
			break ;
		if (r == 0 || !append_val(vals, n, cap, val))
			return (0);
		found = 1;
	}
	return (found);
}

/*
** Tokenize argv entries into a flat int array.
** Returns 1 on success; 0 on error.
*/
int	ps_parse_argv_to_ints(int argc, char **argv, int start,
		int **out_vals, int *out_n)
{
	int	*vals;
	int	cap;
	int	n;
	int	i;

	vals = NULL;
	cap = 0;
	n = 0;
	i = start;
	while (i < argc)
	{
		if (!parse_arg_tokens(argv[i], &vals, &n, &cap))
			return (free(vals), 0);
		i++;
	}
	*out_vals = vals;
	*out_n = n;
	return (1);
}
