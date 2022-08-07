/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:23:48 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/06/06 13:27:34 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	size_t	i;
	char	*ptr_join;

	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	ptr_join = (char *) malloc(len);
	if (!s1 || !s2 || !ptr_join)
		return (NULL);
	i = 0;
	while (*s1)
		ptr_join[i++] = *s1++;
	while (*s2)
		ptr_join[i++] = *s2++;
	ptr_join[i] = '\0';
	return (ptr_join);
}
