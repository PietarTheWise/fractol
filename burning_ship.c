/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:03:52 by pnoutere          #+#    #+#             */
/*   Updated: 2022/06/21 17:09:06 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_ship_loop(t_data *img, int y)
{
	long double	zx;
	long double	zy;
	int			x;

	x = 1;
	while (x <= img->height)
	{
		img->cx = x * img->xscale + img->left;
		img->cy = y * img->yscale + img->top;
		zx = 0;
		zy = 0;
		img->count = 0;
		while ((zx * zx + zy * zy < 4) && (img->count < img->iters))
		{
			img->tempx = zx * zx - zy * zy + img->cx;
			zy = 2 * fabsl(zx * zy) + img->cy;
			zx = img->tempx;
			img->count += 1;
		}
		img->continuous_index = img->count + 1 - log(
				(sqrt(zx * zx + zy * zy) / 2.0f) / log(2)) / log(2);
		my_mlx_pixel_put(img, x, y, color(img->continuous_index));
		x++;
	}
}

void	burning_ship(t_data *img)
{
	int			y;

	img->xscale = img->fractal_width / img->height;
	img->yscale = img->fractal_width / img->height;
	y = 1;
	while (y <= img->height)
	{
		burning_ship_loop(img, y);
		y++;
	}
}
