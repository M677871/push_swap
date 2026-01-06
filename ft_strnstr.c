/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:26:28 by miissa            #+#    #+#             */
/*   Updated: 2025/11/08 09:42:57 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t	i;
	size_t	j;

	if (!*to_find)
		return ((char *)str);
	i = 0;
	while (str[i] && i < size)
	{
		j = 0;
		while (str[i + j] && to_find[j]
			&& str[i + j] == to_find[j]
			&& (i + j) < size)
			j++;
		if (!to_find[j])
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
