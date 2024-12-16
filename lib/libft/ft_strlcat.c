/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:51:29 by estferna          #+#    #+#             */
/*   Updated: 2024/10/30 12:55:58 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_length;
	size_t	src_length;

	src_length = ft_strlen(src);
	dest_length = ft_strlen(dst);
	j = dest_length;
	i = 0;
	if (dest_length < size - 1 && size > 0)
	{
		while (src[i] && dest_length + i < size - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (size <= dest_length)
		return (size + src_length);
	if (dest_length >= size)
		dest_length = size;
	return (dest_length + src_length);
}
/*
#include <stdio.h>

int	main(void)
{
	const char s1[] = "giraffa"
	char *s2;

	int i = 4;
	printf("\nnum: %zu\n",ft_strlcat(s2, s1, i));
}*/