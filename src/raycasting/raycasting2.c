/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:45:43 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/29 14:39:01 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void set_dist_and_step(t_raycast *r)
{
	if (r->ray.dir.x < 0)
	{
		r->step.x = -1;
		r->sidedist.x = (r->ray.pos.x - r->m_pos.x) * r->deltadist.x;
	}
	else
	{
		r->step.x = 1;
		r->sidedist.x = (r->m_pos.x + 1.0 - r->ray.pos.x) * r->deltadist.x;
	}
	if (r->ray.dir.y < 0)
	{
		r->step.y = -1;
		r->sidedist.y = (r->ray.pos.y - r->m_pos.y) * r->deltadist.y;
	}
	else
	{
		r->step.y = 1;
		r->sidedist.y = (r->m_pos.y + 1.0 - r->ray.pos.y) * r->deltadist.y;
	}
}

void get_texturing_values(t_raycast *r, t_data *data)
{
	if (r->side == 0)
	{
		r->wallDist = fabs((r->m_pos.x - r->ray.pos.x + (1 - r->step.x) / 2)
			/ r->ray.dir.x);
		if (r->ray.dir.x > 0)
			r->texNum = 0;
		else
			r->texNum = 1;
		r->wallX = r->ray.pos.y + r->wallDist * r->ray.dir.y;
	}
	else
	{
		r->wallDist = fabs((r->m_pos.y - r->ray.pos.y + (1 - r->step.y) / 2)
			/ r->ray.dir.y);
		if (r->ray.dir.y > 0)
			r->texNum = 2;
		else
			r->texNum = 3;
		r->wallX = r->ray.pos.x + r->wallDist * r->ray.dir.x;
	}
	r->wallX -= floor(r->wallX);
	r->texW = data->surface[r->texNum]->w;
	r->texH = data->surface[r->texNum]->h;
	r->tex.x = r->wallX * r->texH;
	r->lineHeight = abs((int)(SCREEN_HEIGHT / r->wallDist)); // height
}

void hit_wall(t_raycast *r, t_data *data)
{
	while (r->hit == 0) // calculate ray until it hits an object
	{
		if (r->sidedist.x < r->sidedist.y)
		{
			r->sidedist.x += r->deltadist.x;
			r->m_pos.x += r->step.x;
			r->side = 0;
		}
		else
		{
			r->sidedist.y += r->deltadist.y;
			r->m_pos.y += r->step.y;
			r->side = 1;
		}
		if (data->map[r->m_pos.x][r->m_pos.y].value > 0)
		{
			r->hit = 1;
		}
	}
}
void give_draw_values(t_raycast *r)
{
	if (r->lineHeight < 0)
		r->lineHeight = SCREEN_HEIGHT;
	r->drawstart = -r->lineHeight / 2 + SCREEN_HEIGHT / 2; // y1
	if (r->drawstart < 0)
		r->drawstart = 0;
	r->drawend = r->lineHeight / 2 + SCREEN_HEIGHT / 2; // y2
	if (r->drawend >= SCREEN_HEIGHT)
		r->drawend = SCREEN_HEIGHT - 1;
	if (r->drawend < 0)
		r->drawend = SCREEN_HEIGHT - 1;
}

void raycasting2(t_data *data)
{
	t_raycast r;
	t_player player;
	t_point pt;

	pt.x = 0;
	player = data->player;
	while (pt.x < SCREEN_WIDTH)
	{
		set_raycast_values(&r, player, pt.x);
		set_dist_and_step(&r);
		hit_wall(&r, data);
		get_texturing_values(&r, data);
		give_draw_values(&r);
		pt.y = r.drawstart;
		while (pt.y <= r.drawend)
		{
			r.tex.y = (pt.y * 2 - SCREEN_HEIGHT + r.lineHeight)
				* (r.texH / 2) / (r.lineHeight + 1);
			r.color = get_pixel(data->surface[r.texNum],
									 r.tex.x, r.tex.y);
			data->pixels[pt.x + pt.y * SCREEN_WIDTH] = r.color;
			pt.y++;
		}
		floorcaster(data, &r, pt.x);
		pt.x++;
	}
}
