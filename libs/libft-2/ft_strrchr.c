/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:22:09 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/06/03 19:07:35 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	c = (unsigned char) c;
	i = ft_strlen(s);
	while (i > 0 && s[i] != c)
		i--;
	if (i == 0 && c != '\0' && c != s[i])
		return (NULL);
	return ((char *) &s[i]);
}
