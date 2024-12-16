/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:00:32 by estferna          #+#    #+#             */
/*   Updated: 2024/11/01 20:50:12 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (*big && len--)
	{
		if (*big == *little && len + 1 >= little_len)
		{
			i = 0;
			while (i < little_len && big[i] == little[i])
				i++;
			if (i == little_len)
				return ((char *)big);
		}
		big++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*big = "42 sao paulo";
	const char	*little = " ";
	size_t 		len = 6;

	printf("big: %s\n resultado: %s", big,ft_strnstr(big, little, len));
}
*/