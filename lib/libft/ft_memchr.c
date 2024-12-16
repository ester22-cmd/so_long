/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:40:03 by estferna          #+#    #+#             */
/*   Updated: 2024/10/26 16:05:37 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	x;

	x = 0;
	str = (char *)s;
	while (x < n)
	{
		if ((unsigned char)str[x] == (unsigned char)c)
			return ((char *)s + x);
		x++;
	}
	return (NULL);
}
