/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:00:32 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/06/06 21:26:57 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && (unsigned char) c != *s)
		s++;
	if (*s == '\0' && (unsigned char) c != '\0')
		return (NULL);
	return ((char *)s);
}
