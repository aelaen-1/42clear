/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:27:17 by aboukezi          #+#    #+#             */
/*   Updated: 2024/05/17 17:27:17 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
    t_fractal      fract; 

    if ((ac == 2 && ft_strncmp(av[1], "mandelbrot", 1) = 0) 
    || (ac == 4 && ft_strncmp(av[1], "julia", 5) = 0))
    {
        fract.name = av[1];
        if(ft_strncmp(fract.name, "julia", 5) == 0)
        {
            fract.julia_a = atof(av[2]);
            fract.julia_b = atof(av[3]);
        }
        createWindow(&fract);
        render(&fract);
    }
    else
    {
        ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
    return (0);
}
