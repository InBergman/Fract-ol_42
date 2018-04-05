/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbroSet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jcocteau <Jcocteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 10:18:15 by Jcocteau          #+#    #+#             */
/*   Updated: 2018/01/08 10:52:15 by Jcocteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static t_node*     ft_mandelbro_sub(t_node *e)
{
    while(e->n < e->MaxIterations)
    {
        e->Z_re2 = e->Z_re * e->Z_re;
        e->Z_im2 = e->Z_im * e->Z_im;
        if(e->Z_re2 + e->Z_im2 > 4)
        {
            e->isInside = 0;
            break;
        }
        // set formula : Z = Z2 + c
        e->Z_im = 2 * e->Z_re * e->Z_im + e->c_im;
        e->Z_re = e->Z_re2 - e->Z_im2 + e->c_re;
        ++(e->n);
    }
    if(e->n < e->MaxIterations)
    {
        ft_put_pixel(e, e->x, e->y, e->colorTab[e->n]);
        return(e);
    }
    if(e->isInside == 1)
        ft_put_pixel(e, e->x, e->y, 0xFFFFFF);
    return(e);
}

void    ft_mandelbro(t_node *e)
{
	while(e->y < WIN_Y)
	{
		// CONVERTION DES COOR TO COMPLEXE NUMBER
		e->c_im = (e->MaxIm - e->y * e->Im_factor) / e->zoom;
        e->x = 0;
		while(e->x < WIN_X)
		{
            ++(e->x);
			// CONVERTION DES COOR TO COMPLEXE NUMBER
			e->c_re = (e->MinRe + e->x * e->Re_factor) / e->zoom;
			e->Z_re = e->c_re;
			e->Z_im = e->c_im;
			e->isInside = 1;
            e->n = 0;
            e = ft_mandelbro_sub(e);
        }
        ++(e->y);
	}
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
}