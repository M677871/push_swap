/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_readline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/27                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*grow_buf(char *old, int oldcap, int newcap)
{
	char	*n;
	int		i;

	n = (char *)malloc((size_t)newcap);
	if (!n)
		return (free(old), NULL);
	i = 0;
	while (i < oldcap)
	{
		n[i] = old[i];
		i++;
	}
	free(old);
	return (n);
}

static int	ensure_cap(char **line, int *cap, int len)
{
	int	ncap;

	if (len + 2 <= *cap)
		return (1);
	ncap = (*cap == 0) ? 64 : *cap * 2;
	if (!*line)
		*line = (char *)malloc((size_t)ncap);
	else
		*line = grow_buf(*line, *cap, ncap);
	if (!*line)
		return (0);
	*cap = ncap;
	return (1);
}

static int	refill_buf(int fd, char *buf, int *blen, int *bpos)
{
	*blen = (int)read(fd, buf, 4096);
	*bpos = 0;
	if (*blen > 0)
		return (1);
	if (*blen == 0)
		return (0);
	return (-1);
}

static char	*fail_line(char *line, int *err)
{
	if (err)
		*err = 1;
	free(line);
	return (NULL);
}

static int	pull_char(int fd, char *buf, int *blen, int *bpos, int *err)
{
	int	r;

	if (*bpos >= *blen)
	{
		r = refill_buf(fd, buf, blen, bpos);
		if (r < 0)
		{
			if (err)
				*err = 1;
			return (-1);
		}
		if (r == 0)
			return (0);
	}
	return ((unsigned char)buf[(*bpos)++]);
}

static int	fill_line(int fd, char **line, int *cap, int *err,
		char *buf, int *blen, int *bpos)
{
	int	len;
	int	c;
	len = 0;
	while (1)
	{
		c = pull_char(fd, buf, blen, bpos, err);
		if (c <= 0)
			break ;
		if (!ensure_cap(line, cap, len))
		{
			if (err)
				*err = 1;
			return (-1);
		}
		(*line)[len++] = (char)c;
		if (c == '\n')
			break ;
	}
	if (c < 0)
		return (-1);
	return (len);
}

/*
** Minimal line reader using read().
** Returns malloc'ed line INCLUDING '\n' if present; NULL on EOF or error.
*/
char	*ps_readline(int fd, int *err)
{
	static char	buf[4096];
	static int	blen = 0;
	static int	bpos = 0;
	char		*line;
	int			cap;
	int			len;

	if (err)
		*err = 0;
	line = NULL;
	cap = 0;
	len = fill_line(fd, &line, &cap, err, buf, &blen, &bpos);
	if (len <= 0)
	{
		if (len < 0)
			return (fail_line(line, err));
		return (free(line), NULL);
	}
	line[len] = '\0';
	return (line);
}
