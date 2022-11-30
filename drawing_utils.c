/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:34:08 by pnoutere          #+#    #+#             */
/*   Updated: 2022/06/21 17:09:14 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	screen_to_fractal_coords(t_data *img)
{
	img->mouse_percentage[0] = ((long double)
			img->mouse_x) / (long double)img->width;
	img->mouse_percentage[1] = ((long double)
			img->mouse_y) / (long double)img->height;
	img->point_in_fractal[1]
		= img->fractal_width * img->mouse_percentage[1] + img->top;
	img->point_in_fractal[0]
		= img->fractal_width * img->mouse_percentage[0] + img->left;
	img->left = img->point_in_fractal[0] - img->zoom
		* img->mouse_percentage[0] + img->offset_left;
	img->top = img->point_in_fractal[1] - img->zoom
		* img->mouse_percentage[1] + img->offset_top;
	img->fractal_width = img->zoom;
	img->off_mouse_x = 0;
	img->off_mouse_y = 0;
	img->offset_left = 0;
	img->offset_top = 0;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 1920 && y >= 0 && y < 1080)
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_fractal(t_data *img)
{
	if (img->multithread)
	{	
		if (img->fractal_type == 0)
			mandle_multithread(img);
		else if (img->fractal_type == 1)
			julia_multithread(img);
		else if (img->fractal_type == 2)
			burning_multithread(img);
		else if (img->fractal_type == 3)
			celtic_multithread(img);
		else if (img->fractal_type == 4)
			weird_duck_multithread(img);
	}
	else
	{
		screen_to_fractal_coords(img);
		if (img->fractal_type == 1)
			julia(img);
		else if (img->fractal_type == 2)
			burning_ship(img);
		else
			mandlebrot(img);
	}
}
