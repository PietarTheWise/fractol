/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:31:10 by pnoutere          #+#    #+#             */
/*   Updated: 2022/06/21 17:53:14 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_data *img)
{
	img->img = mlx_new_image(img->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

int	initiate_fractal(t_data *img)
{
	init(img);
	draw_fractal(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_destroy_image(img->mlx, img->img);
	return (0);
}

static void	img_initiator_2(t_data *img)
{
	img->offset_top = 0;
	img->offset_left = 0;
	img->scale = 1.0f;
	img->iters = 40;
	img->zoom = 4;
	img->center_x = 0;
	img->center_y = 0;
	img->nb = 0;
	img->mouse_x = img->width / 2;
	img->mouse_y = img->height / 2;
	img->colors = 0;
	img->julia_lock = 0;
	img->multithread = img->toggle;
	img->psychedelic = 1;
}

void	img_initiator(t_data *img, int height, int width, int toggle)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, height, width, "fractol");
	img->width = width;
	img->height = height;
	img->left = -2;
	img->top = -2;
	img->fractal_width = 4;
	img->yside = 4;
	img->subtract = 0.1;
	img->step = (long double)4 / (long double)img->height;
	img->d_step = (long double)4 / (long double)img->height;
	img->state = -1;
	img->scroll = -1;
	img->toggle = toggle;
	img->pan_state = -1;
	img->point_in_julia[0] = -1;
	img->point_in_julia[1] = 0;
	img_initiator_2(img);
}

void	img_reset(t_data *img, int height, int width, int toggle)
{
	img->width = width;
	img->height = height;
	img->left = -2;
	img->top = -2;
	img->fractal_width = 4;
	img->yside = 4;
	img->subtract = 0.1;
	img->step = (long double)4 / (long double)img->height;
	img->d_step = (long double)4 / (long double)img->height;
	img->state = -1;
	img->scroll = -1;
	img->toggle = toggle;
	img->pan_state = -1;
	img->point_in_julia[0] = -1;
	img->point_in_julia[1] = 0;
	img_initiator_2(img);
}
