/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:32:57 by estferna          #+#    #+#             */
/*   Updated: 2024/10/26 16:57:24 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	if (p_dest == p_src)
		return (dest);
	if (p_dest < p_src)
	{
		while (n--)
			*p_dest++ = *p_src++;
	}
	else
	{
		p_dest += n;
		p_src += n;
		while (n--)
			*--p_dest = *--p_src;
	}
	return (dest);
}
