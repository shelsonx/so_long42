/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:20:05 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/06/30 15:15:52 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_digits(unsigned int num)
{
	size_t	c;

	c = 0;
	if (num <= 0)
		c++;
	while (num > 0)
	{
		num = num / 10;
		c++;
	}
	return (c);
}

static char	*alloc_digits(size_t digits)
{
	char	*dest;

	dest = (char *) malloc(sizeof(char) * digits + 1);
	if (!dest)
		return (NULL);
	return (dest);
}

char	*ft_utoa(unsigned int n)
{
	char		*dst;
	size_t		digits;
	size_t		i;
	int			temp;

	if (n == 0)
		return (ft_strdup("0"));
	digits = len_digits(n);
	dst = alloc_digits(digits);
	i = digits - 1;
	while (n > 0)
	{
		temp = n % 10;
		dst[i--] = temp + '0';
		n = n / 10;
	}
	dst[digits] = '\0';
	return (dst);
}
