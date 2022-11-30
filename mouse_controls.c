/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:23:50 by pnoutere          #+#    #+#             */
/*   Updated: 2022/06/21 17:08:29 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deal_mouse(int key, int x, int y, void *param)
{
	t_data	*img;

	img = param;
	if (key == MOUSE_SCROLL_DOWN)
	{
		img->zoom *= 1.2;
		img->iters -= 1;
		img->mouse_x = x;
		img->mouse_y = y;
	}
	if (key == MOUSE_SCROLL_UP)
	{
		img->iters += 1;
		img->zoom /= 1.2;
		img->mouse_x = x;
		img->mouse_y = y;
	}
	if (key == MOUSE_LEFT_BUTTON)
	{
		img->off_point_x = x;
		img->off_point_y = y;
		img->pan_state *= -1;
	}
	initiate_fractal(img);
	return (0);
}

int	deal_mouse_up(int key, int x, int y, void *param)
{
	t_data	*img;

	img = param;
	(void)x;
	(void)y;
	if (key == MOUSE_RIGHT_BUTTON)
	{
		if (!img->julia_lock)
			img->julia_lock = 1;
		else
			img->julia_lock = 0;
	}
	if (key == MOUSE_LEFT_BUTTON)
		img->pan_state *= -1;
	initiate_fractal(img);
	return (0);
}

void	julia_lock_util(int x, int y, t_data *img)
{
	long double	mouse_percentage[2];

	img->mouse_x = x;
	img->mouse_y = y;
	mouse_percentage[0] = (long double)img->mouse_x / (long double)img->width;
	mouse_percentage[1] = (long double)img->mouse_y / (long double)img->height;
	img->point_in_julia[0] = img->fractal_width
		* mouse_percentage[0] + img->left;
	img->point_in_julia[1] = img->fractal_width
		* mouse_percentage[1] + img->top;
}

int	deal_mouse_movement(int x, int y, void *param)
{
	t_data	*img;

	img = param;
	if ((img->fractal_type != 1 || img->julia_lock))
	{
		if (img->state == 1)
			julia_lock_util(x, y, img);
	}
	else
		julia_lock_util(x, y, img);
	if (img->pan_state == 1)
	{
		img->off_mouse_x = img->off_point_x - x;
		img->off_mouse_y = img->off_point_y - y;
		img->offset_left = img->zoom * (((long double)
					img->off_mouse_x) / 10000);
		img->offset_top = img->zoom * (((long double)
					img->off_mouse_y) / 10000);
	}
	initiate_fractal(img);
	return (0);
}
