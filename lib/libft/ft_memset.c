/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:48:46 by estferna          #+#    #+#             */
/*   Updated: 2024/11/01 20:48:15 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = (char)c;
		i++;
	}
	return (s);
}

// int main (void)
// {
// 	char str[10];
// 	size_t n = 10;
// 	char *result= ft_memset(str,'a',10);
// 	printf("%s",result);
// 	return (0);
// }
