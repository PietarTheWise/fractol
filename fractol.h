/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:28:49 by pnoutere          #+#    #+#             */
/*   Updated: 2022/06/22 11:13:27 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <pthread.h>
# include <stdlib.h>

# define MOUSE_LEFT_BUTTON	1
# define MOUSE_RIGHT_BUTTON	2
# define MOUSE_THIRD_BUTTON	3
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define MOUSE_SCROLL_LEFT	6
# define MOUSE_SCROLL_RIGHT	7

# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124

# define NUM_PAD_0			82
# define NUM_PAD_1			83
# define NUM_PAD_2			84
# define NUM_PAD_3			85
# define NUM_PAD_4			86
# define NUM_PAD_5			87
# define NUM_PAD_6			88
# define NUM_PAD_7			89
# define NUM_PAD_8			91
# define NUM_PAD_9			92
# define NUM_PAD_PLUS		69
# define NUM_PAD_MINUS		78

# define MAIN_PAD_ESC		53
# define MAIN_PAD_I			34
# define MAIN_PAD_L			37
# define MAIN_PAD_P			35
# define MAIN_PAD_Z			6
# define MAIN_PAD_U			32
# define MAIN_PAD_0			29
# define MAIN_PAD_1			18
# define MAIN_PAD_2			19
# define MAIN_PAD_3			20
# define MAIN_PAD_4			21
# define MAIN_PAD_5			23
# define MAIN_PAD_6			22
# define MAIN_PAD_7			26
# define MAIN_PAD_8			28
# define MAIN_PAD_9			25
# define MAIN_PAD_PLUS		24
# define MAIN_PAD_MINUS		27
# define MAIN_PAD_LESS		43
# define MAIN_PAD_MORE		47

union	u_colour
{
	unsigned int	number;
	unsigned char	channels[4];
};

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	int				state;
	int				pan_state;
	int				scroll;
	char			*addr;
	void			*img;
	int				status;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				count;
	int				iters;
	long double		step;
	long double		offset_top;
	long double		offset_left;
	long double		scale;
	long double		d_step;
	long double		zoom;
	long double		center_x;
	long double		center_y;
	long double		top;
	long double		left;
	long double		fractal_width;
	long double		yside;
	long double		subtract;
	long double		xscale;
	long double		yscale;
	long double		cx;
	long double		cy;
	long double		tempx;
	int				start;
	int				end;
	int				mouse_x;
	int				mouse_y;
	int				nb;
	int				toggle;
	int				colors;
	int				julia_lock;
	long double		point_in_fractal[2];
	long double		point_in_julia[2];
	long double		mouse_percentage[2];
	int				multithread;
	int				psychedelic;
	int				fractal_type;
	int				x;
	int				y;
	float			continuous_index;
	int				off_mouse_y;
	int				off_mouse_x;
	int				off_point_x;
	int				off_point_y;
}				t_data;

typedef struct s_draw
{
	char			*addr;
	void			*img;
	int				width;
	int				height;
	int				nb;
	long double		zoom;
	long double		xscale;
	long double		yscale;
	long double		cx;
	long double		cy;
	int				count;
	int				iters;
	long double		tempx;
	long double		top;
	long double		left;
	int				bits_per_pixel;
	int				line_length;
	long double		fractal_width;
	long double		point_in_fractal[2];
	long double		point_in_julia[2];
	float			continuous_index;
	int				psychedelic;
}				t_draw;

int				deal_key(int key, void *param);
int				deal_mouse(int key, int x, int y, void *param);
int				deal_mouse_up(int key, int x, int y, void *param);
int				deal_mouse_movement(int x, int y, void *param);
void			ctrl_hooks(t_data *img);
void			init(t_data *img);
void			init_grid(t_data *utils);
void			img_initiator(t_data *img, int height, int width, int toggle);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				render_next_frame(void *structure);
int				initiate_fractal(t_data *img);
void			looper(t_data *img, int height, int width, int toggle);
int				initiate_fractal(t_data *img);
unsigned int	color(float continuous_index);
void			screen_to_fractal_coords(t_data *img);
void			mandle_multithread(t_data *img);
void			julia_multithread(t_data *img);
void			assign_tab(t_data *img, t_draw *tab, int i);
void			burning_multithread(t_data *img);
void			celtic_multithread(t_data *img);
void			weird_duck_multithread(t_data *img);
void			burning_ship(t_data *img);
void			mandlebrot(t_data *img);
void			julia(t_data *img);
void			draw_fractal(t_data *img);
void			img_reset(t_data *img, int height, int width, int toggle);

#endif
