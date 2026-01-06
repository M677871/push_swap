/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:28:43 by miissa            #+#    #+#             */
/*   Updated: 2025/11/08 09:41:54 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	size_t			i;
	unsigned char	search;
	unsigned char	*ss;

	i = 0;
	search = (unsigned char) c;
	ss = (unsigned char *) s;
	while (i < size)
	{
		if (ss[i] == search)
			return (&ss[i]);
		i++;
	}
	return (NULL);
}
