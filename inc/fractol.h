/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jcocteau <Jcocteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:46:30 by mberedda          #+#    #+#             */
/*   Updated: 2018/01/08 10:09:22 by Jcocteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>

# define WIN_Y 600
# define WIN_X 1050

// # define KEYPRESS 2
// # define KEYRELEASE 3
// # define KEYPRESSMASK (1L<<0)
// # define KEYRELEASEMASK (1L<<1)

# define ESC 53
# define MORE 69
# define LESS 78
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define PAGE_UP 116
# define PAGE_DOWN 121
# define RESET 82

typedef struct		s_node
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*imc;
	int 			bpp;
	int 			size_line;
	int				endian;
	
	int 			colorTab[6];
	
	double 			MinRe;
	double 			MaxRe;
	double 			MinIm;
	double 			MaxIm;

	double 			c_im;
	double 			c_re;
	double 			Z_im;
	double 			Z_re;
	double 			Z_im2;
	double 			Z_re2;

	double 			Re_factor;
	double 			Im_factor;

	unsigned 		MaxIterations;
	unsigned 		n;

	unsigned 		y;
	unsigned		x;

	float			zoom;
	int 			isInside;
}					t_node;


void		ft_put_pixel(t_node *e, int x, int y, int color);
void 		ft_mandelbro(t_node *node);
void 		ft_julia(t_node *node);

#endif
