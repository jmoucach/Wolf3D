/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 11:55:03 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/14 16:42:31 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void draw_fov(t_data *data)
{
	int l;
	int fov;
	t_player player;

	player = data->player;
	fov = - player.fov /2;
	l = data->box_length;
		while (fov < player.fov/2)
		{
		drawline(player.screen_pos, (t_point){player.screen_pos.x + l * cos(player.angle + fov * M_PI/180), player.screen_pos.y + l * sin(player.angle + fov* M_PI/180)}, data, 0);
			fov++;
		}
		drawline(player.screen_pos, (t_point){player.screen_pos.x + l * cos(player.angle), player.screen_pos.y + l * sin(player.angle)}, data, 0xff0000);
}
void show_player(t_data *data)
{
	Uint32 *pix;
	t_player player;
	int l;

	player = data->player;
	pix = data->pixels;
	l = data->box_length;
	pix[player.screen_pos.x + player.screen_pos.y * SCREEN_WIDTH] = 0xff0000;
	pix[player.screen_pos.x + 1 + player.screen_pos.y * SCREEN_WIDTH] = 0xff0000;
	pix[player.screen_pos.x + (player.screen_pos.y + 1) * SCREEN_WIDTH] = 0xff0000;
	pix[player.screen_pos.x - 1 + player.screen_pos.y * SCREEN_WIDTH] = 0xff0000;
	pix[player.screen_pos.x + (player.screen_pos.y - 1) * SCREEN_WIDTH] = 0xff0000;
	// draw_fov(data);
	raycast(data);
}
