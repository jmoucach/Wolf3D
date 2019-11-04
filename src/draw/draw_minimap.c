/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 19:15:41 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/04 22:03:23 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void		draw_minimap(t_data *data)
{
	int		x;
	int		y;
	int		colour;
	int		length;

	length = data->box_length;
	y = 0;
	while (y < data->msize.y)
	{
		x = 0;
		while (x < data->msize.x)
		{
			if (data->map[y][x].value == 1 || data->map[y][x].value == 2
				|| data->map[y][x].value == 3)
				colour = 0x8B;
			else
				colour = 0xA9A9A9;
			draw_rect_to_sdl((t_point){x * length, y * length},
			(t_point){x * length + length, y * length + length}, data, colour);
			x++;
		}
		y++;
	}
	show_player(data);
}

/*
** 150 pixels de minimap
*/
