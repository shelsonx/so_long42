/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:41:55 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/06/07 16:49:04 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	len;

	len = nmemb * size;
	if (size != len / nmemb)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (NULL);
	p = (void *) malloc(len);
	if (!p)
		return (NULL);
	ft_bzero(p, len);
	return (p);
}
