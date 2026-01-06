/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:47:55 by marvin            #+#    #+#             */
/*   Updated: 2025/11/15 14:43:47 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rev(char *str)
{
	int		i;
	int		len;
	char	temp;

	len = 0;
	while (str[len])
		len++;
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
		i++;
	}
}

static int	ft_numlen(int n)
{
	int				len;
	unsigned int	x;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		x = -n;
	else
		x = n;
	while (x > 0)
	{
		len++;
		x = x / 10;
	}
	return (len);
}

static void	fill_digits(char *p, unsigned int x, int is_negative)
{
	int	i;

	i = 0;
	while (x > 0)
	{
		p[i++] = x % 10 + '0';
		x = x / 10;
	}
	if (is_negative)
		p[i++] = '-';
	p[i] = '\0';
	ft_rev(p);
}

char	*ft_itoa(int n)
{
	int				is_negative;
	unsigned int	x;
	int				len;
	char			*p;

	if (n == 0)
		return (ft_strdup("0"));
	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	len = ft_numlen(n);
	p = malloc(sizeof(char) * (len + is_negative + 1));
	if (!p)
		return (NULL);
	if (n < 0)
		x = -n;
	else
		x = n;
	fill_digits(p, x, is_negative);
	return (p);
}
