/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 19:15:41 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/05 07:32:34 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void		draw_minimap(t_data *data)
{
	int		x;
	int		y;
	int		colour;
	t_point	length;

	length.x = (0.2 * SCREEN_WIDTH) / data->msize.x;
	length.y = (0.2 * SCREEN_HEIGHT) / data->msize.y;
	y = 0;
	while (y < data->msize.y)
	{
		x = 0;
		while (x < data->msize.x)
		{
			if (data->map[y][x] == 1 || data->map[y][x] == 2
				|| data->map[y][x] == 3)
				colour = 0x8B;
			else
				colour = 0xA9A9A9;
			draw_rect_to_sdl((t_point){x * length.x, y * length.y},
			(t_point){x * length.x + length.x, y * length.y + length.y}, data, colour);
			x++;
		}
		y++;
	}
	show_player(data, length);
}

/*
** 150 pixels de minimap
*/
