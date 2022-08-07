/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:20:05 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/06/08 18:42:19 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_digits(long int num)
{
	size_t	c;

	c = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		c++;
	}
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

char	*ft_itoa(int n)
{
	char		*dst;
	size_t		digits;
	size_t		i;
	int			temp;
	long int	num;

	num = n;
	digits = len_digits(num);
	dst = alloc_digits(digits);
	i = digits - 1;
	if (num == 0)
		dst[0] = '0';
	if (num < 0)
	{
		dst[0] = '-';
		num *= -1;
	}	
	while (num > 0)
	{
		temp = num % 10;
		dst[i--] = temp + '0';
		num = num / 10;
	}
	dst[digits] = '\0';
	return (dst);
}
