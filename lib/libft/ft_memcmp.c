/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:18:31 by estferna          #+#    #+#             */
/*   Updated: 2024/10/30 14:36:29 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*pt1;
	const unsigned char	*pt2;
	size_t				i;

	i = 0;
	pt1 = (const unsigned char *)s1;
	pt2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (pt1[i] != pt2[i])
		{
			return (pt1[i] - pt2[i]);
		}
		i++;
	}
	return (0);
}
