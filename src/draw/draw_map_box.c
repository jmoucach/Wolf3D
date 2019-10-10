/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:24:48 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/09 13:30:24 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void draw_map_box(t_data *data)
{
	int x;
	int y;
	int colour;
	int length;

	length = data->box_length;
	y = 0;
	while (y < data->mapSize.y)
	{
		x = 0;
		while (x < data->mapSize.x)
		{
			if (data->map[y][x].value == 1 || data->map[y][x].value == 2 || data->map[y][x].value == 3)
				colour = 0xff;
	
			else
				colour = 0xffffff;
			draw_rect_to_sdl((t_point){x * length, y* length},
			(t_point){x * length + length, y* length + length}, data, colour);
			x++;
		}
		y++;
	}
}
