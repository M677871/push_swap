/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 07:16:51 by miissa            #+#    #+#             */
/*   Updated: 2026/01/03 13:34:49 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

static char	*dup_ws_as_space(const char *s)
{
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	dup = (char *)ft_calloc(ft_strlen(s) + 1, 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (is_space(s[i]))
			dup[i] = ' ';
		else
			dup[i] = s[i];
		i++;
	}
	return (dup);
}

void	ps_free_split(char **parts)
{
	int	i;

	if (!parts)
		return ;
	i = 0;
	while (parts[i])
		free(parts[i++]);
	free(parts);
}

char	**ps_split_ws(const char *s)
{
	char	*dup;
	char	**parts;

	dup = dup_ws_as_space(s);
	if (!dup)
		return (NULL);
	parts = ft_split(dup, ' ');
	free(dup);
	if (!parts || !parts[0])
	{
		ps_free_split(parts);
		return (NULL);
	}
	return (parts);
}

int	ps_parse_token(const char *s, int *out)
{
	int	i;
	int	val;

	if (!s || !*s)
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!ft_isdigit(s[i]))
		return (0);
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] != '\0')
		return (0);
	val = ft_atoi(s);
	if (val == INT_MAX || val == INT_MIN)
	{
		if (ft_strncmp(s, "2147483647", 10)
			&& ft_strncmp(s, "-2147483648", 11))
			return (0);
	}
	*out = val;
	return (1);
}
