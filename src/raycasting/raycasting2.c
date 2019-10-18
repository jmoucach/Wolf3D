/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:45:43 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/18 14:50:48 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void raycasting2(t_data *data)
{
	t_player player;

	player = data->player;
	for (int x = 0; x < SCREEN_WIDTH; x++) // for all x on the screen resolution
	{
		double cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
		t_d_point rayPos = {player.pos.x, player.pos.y};
		t_d_point rayDir = {player.dir.x + player.plane.x * cameraX, player.dir.y + player.plane.y * cameraX};
		t_point mapc = {(int)rayPos.x, (int)rayPos.y};
		t_d_point sideDist;
		t_d_point deltaDist = {sqrt(1 + (rayDir.y * rayDir.y) / (rayDir.x * rayDir.x)), sqrt(1 + (rayDir.x * rayDir.x) / (rayDir.y * rayDir.y))};
		double perpWallDist;
		t_point step;
		int hit = 0;
		int side;

		// setting step and sideDist based on rayDir values
		if (rayDir.x < 0)
		{
			step.x = -1;
			sideDist.x = (rayPos.x - mapc.x) * deltaDist.x;
		}
		else
		{
			step.x = 1;
			sideDist.x = (mapc.x + 1.0 - rayPos.x) * deltaDist.x;
		}

		if (rayDir.y < 0)
		{
			step.y = -1;
			sideDist.y = (rayPos.y - mapc.y) * deltaDist.y;
		}
		else
		{
			step.y = 1;
			sideDist.y = (mapc.y + 1.0 - rayPos.y) * deltaDist.y;
		}

		// check if the casted ray has hit an object
		while (hit == 0) // calculate ray until it hits an object
		{
			if (sideDist.x < sideDist.y)
			{
				sideDist.x += deltaDist.x;
				mapc.x += step.x;
				side = 0;
			}
			else
			{
				sideDist.y += deltaDist.y;
				mapc.y += step.y;
				side = 1;
			}
			if (data->map[mapc.x][mapc.y].value > 0) // the ray has hit a non-zero block at position mapc.x, mapc.y
			{
				hit = 1;
			}
		}
		if (side == 0)
		{
			perpWallDist = fabs((mapc.x - rayPos.x + (1 - step.x) / 2) / rayDir.x);
		}
		else
		{
			perpWallDist = fabs((mapc.y - rayPos.y + (1 - step.y) / 2) / rayDir.y);
		}
		int lineHeight = abs((int)(SCREEN_HEIGHT / perpWallDist)); // height
		if (lineHeight < 0)
		{
			lineHeight = SCREEN_HEIGHT;
		}
		int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;	 // y1
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2; // y2
		if (drawEnd >= SCREEN_HEIGHT)
			drawEnd = SCREEN_HEIGHT - 1;
		int color = map(perpWallDist, (t_point){0, SCREEN_WIDTH}, (t_point){255, 0});
		if (side == 1)
			color /= 2;
			drawline((t_point){x, 0}, (t_point){x, drawStart}, data, 0x87CEEB);
		drawline((t_point){x, drawStart}, (t_point){x, drawEnd}, data, color + 256 *color + 256*256 *color);
			drawline((t_point){x, drawEnd}, (t_point){x, SCREEN_HEIGHT}, data, 0x228B22);
	}
}