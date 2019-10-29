/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcaster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:51:01 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/29 17:23:09 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void floorcaster(t_data *data, t_raycast *r, int x)
{
	t_d_point floor;
	t_d_point currentfloor;
	t_point floorTex;
	// t_point pt;
	double distWall = r->wallDist;
	double distPlayer = 0;
	double currentdist = 0;
	double weight;

	if (r->side == 0 && r->ray.dir.x > 0)
	{
		floor.x = r->m_pos.x;
		floor.y = r->m_pos.y + r->wallX;
	}
	else if (r->side == 0 && r->ray.dir.x < 0)
	{
		floor.x = r->m_pos.x + 1.0;
		floor.y = r->m_pos.y + r->wallX;
	}
	else if (r->side == 1 && r->ray.dir.y > 0)
	{
		floor.x = r->m_pos.x + r->wallX;
		floor.y = r->m_pos.y;
	}
	else
	{
		floor.x = r->m_pos.x + r->wallX;
		floor.y = r->m_pos.y + 1.0;
	}

	int y = r->drawend;
	while (y < SCREEN_HEIGHT)
	{
		currentdist = (double)SCREEN_HEIGHT / (double)(2 * y - SCREEN_HEIGHT);
		weight = (currentdist - distPlayer) / (distWall - distPlayer);
		currentfloor.x = weight * floor.x + (1 - weight) * data->player.pos.x;
		currentfloor.y = weight * floor.y + (1 - weight) * data->player.pos.y;
		floorTex.x = (int)(currentfloor.x * r->texW) % r->texW;
		floorTex.y = (int)(currentfloor.y * r->texH) % r->texH;
		int color = (get_pixel(data->surface[4], floorTex.x, floorTex.y) >> 1);
		data->pixels[x + y * SCREEN_WIDTH] = color;
		color = get_pixel(data->surface[5], floorTex.x, floorTex.y);
		data->pixels[x + (SCREEN_HEIGHT - y) * SCREEN_WIDTH] = color;
		// printf("POS:|x:%d, y:%d|,FLOORTEX:|x:%d, y:%d|, COLOR:%d, CURRENTDIST:%f, WEIGHT:%f\n",x, y, floorTex.x, floorTex.y, color, currentdist, weight);
		y++;
	}
}
