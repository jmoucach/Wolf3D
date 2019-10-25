/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:45:43 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/25 12:34:18 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void set_dist_and_step(t_raycast *values)
{
	if (values->ray.dir.x < 0)
	{
		values->step.x = -1;
		values->sidedist.x = (values->ray.pos.x - values->m_pos.x) * values->deltadist.x;
	}
	else
	{
		values->step.x = 1;
		values->sidedist.x = (values->m_pos.x + 1.0 - values->ray.pos.x) * values->deltadist.x;
	}

	if (values->ray.dir.y < 0)
	{
		values->step.y = -1;
		values->sidedist.y = (values->ray.pos.y - values->m_pos.y) * values->deltadist.y;
	}
	else
	{
		values->step.y = 1;
		values->sidedist.y = (values->m_pos.y + 1.0 - values->ray.pos.y) * values->deltadist.y;
	}
}

void get_texturing_values(t_raycast *values, t_data *data)
{
	if (values->side == 0)
		{
			values->wallDist = fabs((values->m_pos.x - values->ray.pos.x + (1 - values->step.x) / 2) / values->ray.dir.x);
			if (values->ray.dir.x > 0)
				values->texNum = 0;
			else
				values->texNum = 1;
			values->wallX = values->ray.pos.y + values->wallDist * values->ray.dir.y;
		}
		else
		{
			values->wallDist = fabs((values->m_pos.y - values->ray.pos.y + (1 - values->step.y) / 2) / values->ray.dir.y);
			if (values->ray.dir.y > 0)
				values->texNum = 2;
			else
				values->texNum = 3;
			values->wallX = values->ray.pos.x + values->wallDist * values->ray.dir.x;
		}
		values->wallX -= floor(values->wallX);
		values->texW = data->surface[values->texNum]->w;
		values->texH = data->surface[values->texNum]->h;
		values->tex.x = values->wallX * values->texH;
		values->lineHeight = abs((int)(SCREEN_HEIGHT / values->wallDist)); // height
}

void hit_wall(t_raycast *values, t_data *data)
{
	while (values->hit == 0) // calculate ray until it hits an object
	{
		if (values->sidedist.x < values->sidedist.y)
		{
			values->sidedist.x += values->deltadist.x;
			values->m_pos.x += values->step.x;
			values->side = 0;
		}
		else
		{
			values->sidedist.y += values->deltadist.y;
			values->m_pos.y += values->step.y;
			values->side = 1;
		}
		if (data->map[values->m_pos.x][values->m_pos.y].value > 0) // the ray has hit a non-zero block at position mapc.x, mapc.y
		{
			values->hit = 1;
		}
	}
}

void raycasting2(t_data *data)
{
	t_raycast values;
	t_player player;
	t_point pt;

	pt.x = 0;
	player = data->player;
	while (pt.x < SCREEN_WIDTH)
	{
		set_raycast_values(&values, player, pt.x);
		set_dist_and_step(&values);
		hit_wall(&values, data);
		get_texturing_values(&values, data);
		if (values.lineHeight < 0)
		{
			values.lineHeight = SCREEN_HEIGHT;
		}
		values.drawstart = -values.lineHeight / 2 + SCREEN_HEIGHT / 2; // y1
		if (values.drawstart < 0)
			values.drawstart = 0;
		values.drawend = values.lineHeight / 2 + SCREEN_HEIGHT / 2; // y2
		if (values.drawend >= SCREEN_HEIGHT)
			values.drawend = SCREEN_HEIGHT - 1;

		pt.y = values.drawstart;
		while (pt.y <= values.drawend)
		{
			values.tex.y = (pt.y * 2 - SCREEN_HEIGHT + values.lineHeight) * (values.texH / 2) / (values.lineHeight + 1);
			values.color = get_pixel(data->surface[values.texNum], values.tex.x, values.tex.y);
			// if (values.side == 1)
			// 	values.color = (values.color >> 1) & 8355711;
			data->pixels[pt.x + pt.y * SCREEN_WIDTH] = values.color;
			pt.y++;
		}
		// drawline((t_point){x, 0}, (t_point){x, values.drawstart}, data, 0x87CEEB);
		// drawline((t_point){x, values.drawend}, (t_point){x, SCREEN_HEIGHT}, data, 0x228B22);
		pt.x++;
	}
}
