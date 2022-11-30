/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juliaset_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:31:40 by pnoutere          #+#    #+#             */
/*   Updated: 2022/06/20 14:48:23 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia_inner_loop(t_data *vals, t_draw *img)
{
	long double	zx;
	long double	zy;

	vals->x = vals->start;
	while (vals->x <= vals->end)
	{
		zy = vals->y * img->yscale + img->top;
		zx = vals->x * img->xscale + img->left;
		img->cx = img->point_in_julia[0];
		img->cy = img->point_in_julia[1];
		img->count = 0;
		while ((zx * zx + zy * zy < 4) && (img->count < img->iters))
		{
			img->tempx = zx * zx - zy * zy + (img->cx);
			zy = 2 * zx * zy + (img->cy);
			zx = img->tempx;
			img->count += 1;
		}
		img->continuous_index = img->count + 34 - log(
				(sqrt(zx * zx + zy * zy) / 2.0f) / log(2)) / log(2);
		my_mlx_pixel_put(vals, vals->x, vals->y, color(img->continuous_index));
		vals->x++;
	}
}

static void	*julia_multi(void *arg)
{
	t_draw	*img;
	t_data	vals;

	img = (t_draw *)arg;
	vals.addr = img->addr;
	vals.line_length = img->line_length;
	vals.bits_per_pixel = img->bits_per_pixel;
	img->xscale = img->fractal_width / img->height;
	img->yscale = img->fractal_width / img->height;
	vals.start = img->nb * (img->height / 8);
	vals.end = (img->nb + 1) * (img->height / 8);
	vals.y = 1;
	while (vals.y <= img->height)
	{
		julia_inner_loop(&vals, img);
		vals.y++;
	}
	return (NULL);
}

void	julia_multithread(t_data *img)
{
	pthread_t	tids[8];
	t_draw		tab[8];
	int			i;

	i = 0;
	screen_to_fractal_coords(img);
	while (i < 8)
	{
		assign_tab(img, &tab[i], i);
		pthread_create(&tids[i], NULL, julia_multi, (void *)&tab[i]);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		pthread_join(tids[i], NULL);
		i++;
	}
}
