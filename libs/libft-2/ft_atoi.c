/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:18:44 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/06/15 15:20:54 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *src)
{
	int	sign;
	int	res;

	while ((*src >= '\t' && *src <= '\r') || *src == 32)
		src++;
	sign = 1;
	res = 0;
	if (*src == '-')
		sign *= -1;
	if (*src == '-' || *src == '+')
		src++;
	while (*src >= '0' && *src <= '9')
	{
		res = (res * 10) + (*src - '0');
		src++;
	}
	return (res * sign);
}
