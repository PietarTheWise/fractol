/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:10:41 by pnoutere          #+#    #+#             */
/*   Updated: 2022/06/20 14:35:53 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	color(float continuous_index)
{
	union u_colour	c;

	c.channels[0] = (unsigned char)
		(sin(0.017 * continuous_index + 4) * 230 + 25);
	c.channels[1] = (unsigned char)
		(sin(0.014 * continuous_index + 2) * 230 + 25);
	c.channels[2] = (unsigned char)
		(sin(0.011 * continuous_index + 1) * 230 + 25);
	c.channels[3] = 255;
	return (ft_abs(c.number));
}
