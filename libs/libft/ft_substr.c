/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:29:39 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/06/14 06:15:31 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr_sub;
	size_t	i;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	ptr_sub = (char *) malloc((len + 1) * sizeof(char));
	if (!ptr_sub)
		return (NULL);
	i = 0;
	while (i < len)
		ptr_sub[i++] = s[start++];
	ptr_sub[i] = '\0';
	return (ptr_sub);
}
