/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27                                 #+#    #+#             */
/*   Updated: 2025/12/27                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_write_char_fd(char c, int fd)
{
	(void)!write(fd, &c, 1);
}

void	ps_write_str_fd(const char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	(void)!write(fd, s, i);
}

int	ps_streq(const char *a, const char *b)
{
	int	i;

	if (!a || !b)
		return (0);
	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] == '\0' && b[i] == '\0');
}

int	ps_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

static void	write_uint(unsigned int n, int fd)
{
	if (n >= 10)
		write_uint(n / 10, fd);
	ps_write_char_fd((char)('0' + (n % 10)), fd);
}

void	ps_write_int_fd(int n, int fd)
{
	long			tmp;
	unsigned int	num;

	tmp = n;
	if (tmp < 0)
	{
		ps_write_char_fd('-', fd);
		tmp = -tmp;
	}
	num = (unsigned int)tmp;
	write_uint(num, fd);
}

void	ps_write_double2_fd(double val, int fd)
{
	long	whole;
	long	frac;

	if (val < 0)
	{
		ps_write_char_fd('-', fd);
		val = -val;
	}
	whole = (long)val;
	frac = (long)((val - (double)whole) * 100.0 + 0.5);
	if (frac == 100)
	{
		whole++;
		frac = 0;
	}
	ps_write_int_fd((int)whole, fd);
	ps_write_char_fd('.', fd);
	if (frac < 10)
		ps_write_char_fd('0', fd);
	ps_write_int_fd((int)frac, fd);
}
