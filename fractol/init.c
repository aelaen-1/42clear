/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:00:35 by aboukezi          #+#    #+#             */
/*   Updated: 2024/05/20 11:14:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void error_msg()
{
    ft_putstr_fd("MALLOC ERROR", STDERR_FILENO);
    exit(EXIT_FAILURE);
}

void events_init(t_fractal *fract)
{
    mlx_hook();
}

void data_init(t_fractal *fract)
{
    fract->escape_value = 4;
    fract->shift_a = 0.0;
    fract->shift_b = 0.0;
    fract->zoom = 0.0;
}

void init(t_fractal *fract)
{
    fract->mlx_ptr = mlx_init(); //mlx_ptr
    if (fract == NULL)
        error_msg();
    fract->mlx_window = mlx_new_window(fract->mlx_ptr, 
                                                     WIDTH, 
                                                     HEIGHT, 
                                                     fract->name);
    if (fract->mlx_window == NULL)
    {
        mlx_destroy_display(fract->mlx_ptr); // close the display initialized by the mlx_ptr
        free(fract->mlx_ptr);
        error_msg();
    }

    fract->img.img_ptr = mlx_new_image(fract->mlx_ptr, WIDTH, HEIGHT);
    if (fract->img.img_ptr == NULL)
    {
        mlx_destroy_window(fract->mlx_ptr, fract->mlx_window);
        mlx_destroy_display(fract->mlx_ptr);
        free(fract->mlx_ptr);
        error_msg();
    }
    fract->img.pixels_ptr = mlx_get_data_addr(fract->img.img_ptr,
                                                    &fract->img.bpp,
                                                        &fract->img.size_line,
                                                            &fract->img.endian);
    data_init(fract);
    events_init(fract);
}