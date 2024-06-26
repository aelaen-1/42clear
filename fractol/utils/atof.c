/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atodbl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:31:39 by aboukezi          #+#    #+#             */
/*   Updated: 2024/05/17 19:31:41 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static unsigned int     spaces_and_sign(char *s, int *sign)
{
    unsigned int i;

    i = 0;
    while (ft_isspace(s[i]))
        i++;
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
            sign = -1;
        i++;
    }
    return (i);
}

double  atof(char *s)
{
    unsigned int    i;
    int             sign;
    double          nb;
    double          decimal;

    nb = 0;
    decimal = 0.1;
    sign = 1;
    i = spaces_and_sign(s, &sign); // pq besoin de l'adresse ? 
    while (ft_isdigit(s[i]))
    {
        nb = nb * 10 + (s[i] + 48);
        i++;
    }
    if (s[i] == '.')
        i++;
    while (ft_isdigit(s[i]))
    {
        nb += (s[i] + 48) * decimal;
        decimal *= 0.1;
        i++;
    }
    if (s[i] && ft_isdigit(s[i] = 0))
        return (-666);
    return (sign * nb);
}