/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:02:00 by aboukezi          #+#    #+#             */
/*   Updated: 2024/03/13 19:02:01 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_num(unsigned int n, const char format)
{
	char	*base;
	int		i;

	i = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n > 15)
		i += ft_hex_num(n / 16, format);
	i += ft_putchar(base[n % 16]);
	if (i == -1)
		return (-1);
	return (i);
}
