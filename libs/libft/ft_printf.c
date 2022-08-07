/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 04:59:57 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/07 16:28:08 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putstr(char *str, int to_free)
{
	int	len;

	len = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
		if (to_free == 1)
			free(str);
		return (len);
	}
}

static int	ft_treat_args(int i, const char *format, va_list args)
{
	int	size;

	size = 0;
	if (format[i] == '%' || format[i] == 'c')
	{
		if (format[i] == '%')
			ft_putchar_fd(format[i], 1);
		else if (format[i] == 'c')
			ft_putchar_fd(va_arg(args, int), 1);
		size++;
	}
	else if (format[i] == 's')
		size += ft_putstr(va_arg(args, char *), 0);
	else if (format[i] == 'i' || format[i] == 'd')
		size += ft_putstr(ft_itoa(va_arg(args, int)), 1);
	else if (format[i] == 'u')
		size += ft_putstr(ft_utoa(va_arg(args, unsigned int)), 1);
	else if (format[i] == 'x')
		size += ft_putstr(ft_itoa_base(va_arg(args, unsigned int), 16, 'a'), 1);
	else if (format[i] == 'X')
		size += ft_putstr(ft_itoa_base(va_arg(args, unsigned int), 16, 'A'), 1);
	else if (format[i] == 'p')
		size += ft_putstr(ft_ptr_hex(((long int) va_arg(args, void *)), 16), 1);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		size;

	if (!format)
		return (0);
	va_start(args, format);
	i = 0;
	size = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			i++;
			size += ft_treat_args(i, format, args);
		}
		else
		{	
			ft_putchar_fd(format[i], 1);
			size++;
		}
		i++;
	}
	va_end(args);
	return (size);
}
