/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:42:16 by estferna          #+#    #+#             */
/*   Updated: 2024/11/06 18:15:31 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*index;
	size_t	overflow;

	overflow = size * nmemb;
	if (nmemb != 0 && size != 0 && overflow / nmemb != size)
		return (NULL);
	index = malloc(nmemb * size);
	if (index == NULL)
		return (NULL);
	ft_memset(index, 0, nmemb * size);
	return (index);
}
