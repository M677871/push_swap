/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:26:39 by miissa            #+#    #+#             */
/*   Updated: 2025/11/15 07:23:37 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*joined;
	size_t	i;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (!joined)
		return (NULL);
	i = 0;
	while (i < size_s1)
	{
		joined[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < size_s2)
	{
		joined[size_s1 + i] = s2[i];
		i++;
	}
	joined[size_s1 + size_s2] = '\0';
	return (joined);
}
