/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:48:44 by aboukezi          #+#    #+#             */
/*   Updated: 2024/02/04 17:48:48 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	wordlen(int n)
{
	unsigned int	len;

	len = 0;
	if (n <= 0)
	{
		if (n == 0)
			return (1);
		n *= -1;
		len = 1;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	long long int	nb;
	unsigned int	len;

	nb = n;
	len = wordlen(nb);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
	else
		ft_putchar (nb + 48);
	return (len);
}
