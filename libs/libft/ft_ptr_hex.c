/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:49:53 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/07 16:28:53 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_digits(unsigned long int num, int base)
{
	size_t	c;

	c = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / base;
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

char	*ft_utoa_u(unsigned long int n, int base)
{
	char		*dst;
	size_t		digits;
	size_t		i;
	int			temp;

	if (n == 0)
		return (ft_strdup("(nil)"));
	digits = len_digits(n, base);
	dst = alloc_digits(digits);
	i = digits - 1;
	while (n > 0)
	{
		temp = n % base;
		if (temp < 10)
			dst[i--] = temp + '0';
		else
			dst[i--] = ('a' + temp - 10);
		n = n / base;
	}
	dst[digits] = '\0';
	return (dst);
}

char	*ft_ptr_hex(unsigned long int n, int base)
{
	char	*initial;
	char	*hex;
	char	*joinned;

	if (n == 0)
		return (ft_utoa_u(n, base));
	initial = "0x";
	hex = ft_utoa_u(n, base);
	joinned = ft_strjoin(initial, hex);
	free(hex);
	return (joinned);
}
