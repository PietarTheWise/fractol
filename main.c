/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:05:14 by pnoutere          #+#    #+#             */
/*   Updated: 2022/06/21 18:26:22 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ctrl_hooks(t_data *img)
{
	mlx_hook(img->win, 2, 0, &deal_key, img);
	mlx_hook(img->win, 4, 0, &deal_mouse, img);
	mlx_hook(img->win, 5, 0, &deal_mouse, img);
	mlx_hook(img->win, 5, 0, &deal_mouse_up, img);
	mlx_hook(img->win, 6, 0, &deal_mouse_movement, img);
}

void	looper(t_data *img, int height, int width, int toggle)
{
	img_initiator(img, height, width, toggle);
	initiate_fractal(img);
	ctrl_hooks(img);
	mlx_loop(img->mlx);
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc != 2)
	{
		ft_putendl("Available parameters:\n");
		ft_putendl("mandlebrot set\njulia set\nburning ship");
		return (0);
	}
	if (!ft_strcmp(argv[1], "mandlebrot set"))
		img.fractal_type = 0;
	else if (!ft_strcmp(argv[1], "julia set"))
		img.fractal_type = 1;
	else if (!ft_strcmp(argv[1], "burning ship"))
		img.fractal_type = 2;
	else
	{
		ft_putendl("Available parameters:\n");
		ft_putendl("mandlebrot set\njulia set\nburning ship");
		exit(1);
	}
	looper(&img, 544, 544, 0);
	return (1);
}
