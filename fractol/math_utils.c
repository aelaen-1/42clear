/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:27:33 by aboukezi          #+#    #+#             */
/*   Updated: 2024/05/17 17:27:34 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

t_complex   sum(t_complex z1, t_complex z2)
{
    t_complex   z; 

    z.a = z1.a + z2.a;
    z.b = z1.b + z2.b;

    return (z);
}

t_complex   square(t_complex z)
{
    t_complex   squared_z;

    squared_z.a = (z.a * z.a) - (z.b * z.b);
    squared_z.b = 2 * z.a * z.b;

    return (squared_z);
}
