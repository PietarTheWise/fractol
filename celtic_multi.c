/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic_multi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:05:05 by pnoutere          #+#    #+#             */
/*   Updated: 2022/06/21 17:09:07 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	celtic_inner_loop(t_data *values, t_draw *img)
{
	long double	zx;
	long double	zy;

	values->x = values->start;
	while (values->x <= values->end)
	{
		img->cy = values->y * img->yscale + img->top;
		img->cx = values->x * img->xscale + img->left;
		zx = 0;
		zy = 0;
		img->count = 0;
		while ((zx * zx + zy * zy < 4) && (img->count < img->iters))
		{
			img->tempx = fabsl(zx * zx - zy * zy) + img->cx;
			zy = 2 * zx * zy + img->cy;
			zx = img->tempx;
			img->count += 1;
		}
		img->continuous_index = img->count + 1 - log(
				(sqrt(zx * zx + zy * zy) / 2.0f) / log(2)) / log(2);
		my_mlx_pixel_put(values, values->x,
			values->y, color(img->continuous_index));
		values->x++;
	}
}

static void	*celtic_multi(void *arg)
{
	t_draw	*img;
	t_data	values;

	img = (t_draw *)arg;
	values.addr = img->addr;
	values.line_length = img->line_length;
	values.bits_per_pixel = img->bits_per_pixel;
	img->xscale = img->fractal_width / img->height;
	img->yscale = img->fractal_width / img->height;
	values.start = img->nb * (img->width / 8);
	values.end = (img->nb + 1) * (img->width / 8);
	values.y = 1;
	while (values.y <= img->height)
	{
		celtic_inner_loop(&values, img);
		values.y++;
	}
	return (NULL);
}

void	celtic_multithread(t_data *img)
{
	pthread_t	tids[8];
	t_draw		tab[8];
	int			i;

	i = 0;
	screen_to_fractal_coords(img);
	while (i < 8)
	{
		assign_tab(img, &tab[i], i);
		pthread_create(&tids[i], NULL, celtic_multi, (void *)&tab[i]);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		pthread_join(tids[i], NULL);
		i++;
	}
}
