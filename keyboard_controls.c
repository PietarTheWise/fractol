/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:36:56 by pnoutere          #+#    #+#             */
/*   Updated: 2022/06/21 18:06:47 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	deal_key_utils(int key, t_data *img)
{
	if (key == MAIN_PAD_I)
	{
		mlx_destroy_window(img->mlx, img->win);
		if (!img->toggle)
		{
			img->toggle = 1;
			img->multithread = 1;
			img->iters = 60;
			looper(img, 744, 744, 1);
		}
		else
		{
			img->multithread = 0;
			img->iters = 40;
			looper(img, 544, 544, 0);
		}
	}
	if (key == MAIN_PAD_PLUS || key == NUM_PAD_PLUS)
		img->iters++;
	if (key == MAIN_PAD_MINUS || key == NUM_PAD_MINUS)
		img->iters--;
	initiate_fractal(img);
}

int	deal_key(int key, void *param)
{
	t_data	*img;

	img = param;
	if (key == MAIN_PAD_ESC)
		exit (0);
	if (key == MAIN_PAD_P)
	{
		img_reset(img, img->height, img->width, img->toggle);
		img->julia_lock = 0;
		img->fractal_type++;
		if (img->fractal_type > 2 && !img->multithread)
			img->fractal_type = 0;
		else if (img->fractal_type > 4)
			img->fractal_type = 0;
	}
	deal_key_utils(key, img);
	return (0);
}
