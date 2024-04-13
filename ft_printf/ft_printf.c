/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:51:44 by aboukezi          #+#    #+#             */
/*   Updated: 2024/03/13 13:51:45 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list arglist, const char fmt)
{
	int	print_length;

	print_length = 0;
	if (fmt == 'c')
		print_length += ft_putchar(va_arg(arglist, int));
	else if (fmt == 's')
		print_length += ft_putstr(va_arg(arglist, char *));
	else if (fmt == 'd' || fmt == 'i')
		print_length += ft_putnbr(va_arg(arglist, int));
	else if (fmt == 'u')
		print_length += ft_putunbr(va_arg(arglist, unsigned int));
	else if (fmt == '%')
		print_length += ft_putchar('%');
	else if (fmt == 'x' || fmt == 'X')
		print_length += ft_hex_num(va_arg(arglist, unsigned int), fmt);
	else if (fmt == 'p')
		print_length += ft_printhex(va_arg(arglist, unsigned long long));
	return (print_length);
}

int	ft_printf(const char *format, ...)
{
	int		print_length;
	int		i;
	va_list	arglist;

	i = 0;
	print_length = 0;
	if (!format)
		return (-1);
	va_start(arglist, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			print_length += ft_format(arglist, format[i + 1]);
			i++;
		}
		else
			print_length += ft_putchar(format[i]);
		i++;
	}
	va_end(arglist);
	return (print_length);
}
/*va_start(va_list, last known parameter)*/
