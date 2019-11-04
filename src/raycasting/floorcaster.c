/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcaster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:51:01 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/04 18:35:38 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void			floor_side(t_floorcast *f, t_raycast *r)
{
	if (r->side == 0 && r->ray.dir.x > 0)
	{
		f->floor.x = r->m_pos.x;
		f->floor.y = r->m_pos.y + r->wall;
	}
	else if (r->side == 0 && r->ray.dir.x < 0)
	{
		f->floor.x = r->m_pos.x + 1.0;
		f->floor.y = r->m_pos.y + r->wall;
	}
	else if (r->side == 1 && r->ray.dir.y > 0)
	{
		f->floor.x = r->m_pos.x + r->wall;
		f->floor.y = r->m_pos.y;
	}
	else
	{
		f->floor.x = r->m_pos.x + r->wall;
		f->floor.y = r->m_pos.y + 1.0;
	}
}

void			floorcaster(t_data *data, t_raycast *r, int x)
{
	t_floorcast	f;
	int			y;
	int			color;

	y = r->drawend;
	f.currentdist = 0;
	floor_side(&f, r);
	while (y < SCREEN_HEIGHT)
	{
		f.currentdist = (double)SCREEN_HEIGHT / (double)(2 * y - SCREEN_HEIGHT);
		f.weight = f.currentdist / r->wallDist;
		f.currentfloor.x = f.weight * f.floor.x
			+ (1 - f.weight) * data->p.pos.x;
		f.currentfloor.y = f.weight * f.floor.y
			+ (1 - f.weight) * data->p.pos.y;
		f.floorTex.x = (int)(f.currentfloor.x * 64) % 64;
		f.floorTex.y = (int)(f.currentfloor.y * 64) % 64;
		color = (get_pixel(data->surface[4], f.floorTex.x, f.floorTex.y) >> 1);
		data->pixels[x + y * SCREEN_WIDTH] = color;
		color = get_pixel(data->surface[5], f.floorTex.x, f.floorTex.y);
		data->pixels[x + (SCREEN_HEIGHT - y) * SCREEN_WIDTH] = color;
		y++;
	}
}
