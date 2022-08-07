/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:22:06 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/06/07 21:38:11 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	l_trim(char const *s1, char const *set)
{
	size_t	count;

	count = 0;
	while (ft_strchr(set, *s1) && *s1)
	{
		s1++;
		count++;
	}
	return (count);
}

static size_t	r_trim(char const *s1, char const *set)
{
	size_t	count;

	count = ft_strlen(s1);
	while (ft_strchr(set, s1[count - 1]) && count)
		count--;
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_r;
	size_t	len_l;

	len_l = l_trim(s1, set);
	s1 += len_l;
	len_r = r_trim(s1, set);
	return (ft_substr(s1, 0, len_r));
}
