/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:00:35 by aboukezi          #+#    #+#             */
/*   Updated: 2024/05/18 17:00:36 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void error_msg()
{
    ft_putstr("MALLOC ERROR");
    exit(EXIT_FAILURE);
}

void manageWindow(t_fractal *fract)
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
                                                    fract->img.bpp,
                                                        fract->img.size_line,
                                                            fract->img.endian);
}