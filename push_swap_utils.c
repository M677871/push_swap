/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:14:12 by miissa            #+#    #+#             */
/*   Updated: 2026/01/03 13:00:30 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_sign(double *val, int fd)
{
	if (*val < 0)
	{
		ft_putchar_fd('-', fd);
		*val = -(*val);
	}
}

static void	split_parts(double val, long *whole, long *frac)
{
	*whole = (long)val;
	*frac = (long)((val - (double)(*whole)) * 100.0 + 0.5);
	if (*frac == 100)
	{
		(*whole)++;
		*frac = 0;
	}
}

static void	put_two_digits(long n, int fd)
{
	ft_putchar_fd((char)('0' + ((n / 10) % 10)), fd);
	ft_putchar_fd((char)('0' + (n % 10)), fd);
}

void	ps_putdouble2_fd(double val, int fd)
{
	long	whole;
	long	frac;

	put_sign(&val, fd);
	split_parts(val, &whole, &frac);
	ft_putnbr_fd((int)whole, fd);
	ft_putchar_fd('.', fd);
	put_two_digits(frac, fd);
}

void	ps_putpercent2_fd(double val, int fd)
{
	ps_putdouble2_fd(val, fd);
	ft_putchar_fd('%', fd);
}
