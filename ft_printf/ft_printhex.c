/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:49:13 by aboukezi          #+#    #+#             */
/*   Updated: 2024/02/04 17:49:14 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned long long ull)
{
	unsigned int	len;

	len = 0;
	if (ull == 0)
		return (1);
	while (ull)
	{
		ull = ull / 16;
		len++;
	}
	return (len);
}

void	ft_ull_to_hex(unsigned long long ull)
{
	if (ull >= 16)
	{
		ft_ull_to_hex(ull / 16);
		ft_ull_to_hex(ull % 16);
	}
	else
	{
		if (ull <= 9)
			ft_putchar(ull + 48);
		else
			ft_putchar(ull - 10 + 'a');
	}
}

int	ft_printhex(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	if (!ptr || ptr == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	else
	{
		print_length += ft_hexlen(ptr);
		print_length += ft_putstr("0x");
		ft_ull_to_hex(ptr);
	}
	return (print_length);
}
