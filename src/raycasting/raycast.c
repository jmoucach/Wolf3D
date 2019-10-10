/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:19:42 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/09 13:20:30 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

// void cast_ray(t_data *data)
// {
// 	int x;
// 	t_player player;
// 	int color;

// 	player = data->player;
// 	x = 0;
// 	int side;
// 	while (x < SCREEN_WIDTH)
// 	{
// 		double cameraX = 2 * x / SCREEN_WIDTH - 1;
// 		t_d_point rayPos = {player.pos.x, player.pos.y};
// 		t_d_point rayDir = {player.dir.x + player.plane.x * cameraX, player.dir.y + player.plane.y * cameraX};
// 		t_point mapc = {(int)rayPos.x, (int)rayPos.y};
// 		t_d_point sideDist;
// 		t_d_point deltaDist = {sqrt(1 + (rayDir.y * rayDir.y) / (rayDir.x * rayDir.x)), sqrt(1 + (rayDir.x * rayDir.x) / (rayDir.y * rayDir.y))};
// 		double perpWallDist;
// 		t_point step;
// 		int hit = 0;

// 		if (rayDir.x < 0)
// 		{
// 			step.x = -1;
// 			sideDist.x = (rayPos.x - mapc.x) * deltaDist.x;
// 		}
// 		else
// 		{
// 			step.x = 1;
// 			sideDist.x = (mapc.x + 1.0 - rayPos.x) * deltaDist.x;
// 		}

// 		if (rayDir.y < 0)
// 		{
// 			step.y = -1;
// 			sideDist.y = (rayPos.y - mapc.y) * deltaDist.y;
// 		}
// 		else
// 		{
// 			step.y = 1;
// 			sideDist.y = (mapc.y + 1.0 - rayPos.y) * deltaDist.y;
// 		}

// 		// check if the casted ray has hit an object
// 		while (hit == 0) // calculate ray until it hits an object
// 		{
// 			if (sideDist.x < sideDist.y)
// 			{
// 				sideDist.x += deltaDist.x;
// 				mapc.x += step.x;
// 				side = 0;
// 			}
// 			else
// 			{
// 				sideDist.y += deltaDist.y;
// 				mapc.y += step.y;
// 				side = 1;
// 			}

// 			if (data->map[mapc.x][mapc.y].value > 0) // the ray has hit a non-zero block at position mapc.x, mapc.y
// 			{
// 				hit = 1;
// 			}
// 		}
// 		// if (side == 0)
// 		// {
// 		// 	// perpWallDist = fabs((mapc.x - rayPos.x + (1 - step.x) / 2) / rayDir.x);
// 		// }
// 		// else
// 		// {
// 		// 	perpWallDist = fabs((mapc.y - rayPos.y + (1 - step.y) / 2) / rayDir.y);
// 		// }
// 		perpWallDist = sqrt((mapc.x - rayPos.x) * (mapc.x - rayPos.x) + (mapc.y - rayPos.y) * (mapc.y - rayPos.y)) * cos(sqrt((mapc.x - rayPos.x) * (mapc.x - rayPos.x) + (mapc.y - rayPos.y) * (mapc.y - rayPos.y))/sqrt(player.dir.x * player.dir.x + player.dir.y * player.dir.y));
// 		int lineHeight = ft_abs((int)SCREEN_HEIGHT / perpWallDist); // height

// 		int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;	 // y1
// 		if (drawStart < 0)
// 			drawStart = 0;
// 		int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2; // y2
// 		if (drawEnd >= SCREEN_HEIGHT)
// 			drawEnd = SCREEN_HEIGHT - 1;
// 		if (data->map[mapc.x][mapc.y].value == 1)
// 			color = 0xff;
// 		else if (data->map[mapc.x][mapc.y].value == 2)
// 			color = 0xffff;
// 		else
// 			color = 0x00ffff;
		
// 	if (side == 1)
// 		color /= 2;
// 	drawline((t_point){x, drawStart}, (t_point){x, drawEnd}, data, color);
// 	drawline((t_point){x, drawEnd}, (t_point){x, SCREEN_HEIGHT}, data, 0x00ff00);
// 	drawline((t_point){x, 0}, (t_point){x, drawStart}, data, 0xff0000);

// 		x++;
// 	}
// 	return;
// }

void cast_ray(t_data *data)
{
	(void)data;
}

