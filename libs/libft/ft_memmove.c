/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:17:29 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/06/14 02:40:48 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*p_src;
	char	*p_dest;

	p_src = (char *) src;
	p_dest = (char *) dest;
	if (p_dest > p_src)
	{
		p_src += n - 1;
		p_dest += n - 1;
		while (n--)
			*p_dest-- = *p_src--;
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
