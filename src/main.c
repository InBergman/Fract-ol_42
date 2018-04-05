/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jcocteau <Jcocteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:43:19 by mberedda          #+#    #+#             */
/*   Updated: 2018/01/08 10:52:09 by Jcocteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		ft_put_pixel(t_node *e, int x, int y, int color)
{
	int *tmp;

	// if (y >= WIN_Y || x >= WIN_X || x < 0 || y < 0)
	// 	return ;
	tmp = (int*)&e->imc[(y * e->size_line) + (x * (e->bpp / 8))];
	*tmp = color;
}

void ft_init(t_node *e)
{
	e->colorTab[0] = 0xe6ecec;
	e->colorTab[1] = 0xeecfa1;
	e->colorTab[2] = 0xcdb7b5;
	e->colorTab[3] = 0xeed5d2;
	e->colorTab[4] = 0xd3d3d3;
	e->colorTab[5] = 0xcdc1c5;
	e->zoom = 4.9;
	e->isInside = 1;
	e->n = 0;
	e->MinRe = -2.6;
	e->MaxRe = 2;
	e->MinIm = -1.3;
	e->MaxIm = (e->MinIm + (e->MaxRe - e->MinRe) * WIN_Y / WIN_X);

	e->Re_factor = (e->MaxRe - e->MinRe) / (WIN_X);
	e->Im_factor = (e->MaxIm - e->MinIm) / (WIN_Y);
	
	e->MaxIterations = 30;

	e->y = 0;
	e->x = 0;
}

int		main(int argc, char **argv)
{
	t_node	node;

	argv = NULL;
	if (argc == 2)
	{
		// ft_parsing(&e, argv[1]);
		ft_init(&node);
		node.mlx_ptr = mlx_init();
		node.win_ptr = mlx_new_window(node.mlx_ptr, WIN_X, WIN_Y, "fractol");
		node.img_ptr = mlx_new_image(node.mlx_ptr, WIN_X, WIN_Y);
		node.imc = mlx_get_data_addr(node.img_ptr, &(node.bpp), &(node.size_line), &(node.endian));
		ft_mandelbro(&node);
		// ft_julia(&node);
		// mlx_mouse_hook(node.win_ptr, ft_key_biding, void *param );
		// mlx_string_put(node.mlx_ptr, node.win_ptr, 10, 5, node.color, "FRACTOL");
		// mlx_hook(node.win_ptr, KEYPRESS, KEYPRESSMASK, ft_key_biding, &node);
		// mlx_hook(node.win_ptr, KEYRELEASE, KEYRELEASEMASK, ft_key_release, &node);
		// mlx_loop_hook(node.mlx, ft_key_core, &node);
		mlx_loop(node.mlx_ptr);
	}
	return (0);
}
