/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:19:42 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/17 18:39:14 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

int map(int value, t_point input, t_point output)
{
	double slope;
	int ret;

	slope = 1.0 * (output.y - output.x) / (input.y - input.x);
	ret = output.x + round(slope * (value - input.x));
	return (ret);
}

t_point cast_ray_to_edge(t_ray ray, t_edge edge)
{
	double div;
	double t;
	double u;
	t_point pt;

	double x1 = edge.start.x;
	double y1 = edge.start.y;
	double x2 = edge.end.x;
	double y2 = edge.end.y;

	double x3 = ray.pos.x;
	double y3 = ray.pos.y;
	double x4 = ray.pos.x + ray.dir.x;
	double y4 = ray.pos.y + ray.dir.y;
	div = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	if (div == 0)
		return ((t_point){-1, -1});
	else
	{
		t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / div;
		u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / div;
		if (t >= 0 && t <= 1 && u > 0)
		{
			// 	printf("dir:X:%f, Y:%f\n", ray.dir.x, ray.dir.y);
			// printf("T:%f, U:%f\n", t, u);
			pt.x = x3 - u * (x3 - x4);
			pt.y = y3 - u * (y3 - y4);
			return (pt);
		}
		else
			return ((t_point){-1, -1});
	}
}

void raycast(t_data *data)
{
	double fov;
	t_point pt;
	t_ray ray;
	int i;
	double record;
	t_point closest;
	double d;
	double fov_precision;
	int *scene;
	int j;

	fov_precision = 0.25;
	fov = -data->player.fov / 2;
	if (!(scene = (int *)malloc(sizeof(double) * (data->player.fov / fov_precision))))
		return;
	j = 0;
	while (fov <= data->player.fov / 2)
	{
		record = INFINITY;
		i = 0;
		ray.pos.x = data->player.screen_pos.x;
		ray.pos.y = data->player.screen_pos.y;
		ray.dir.x = cos(data->player.angle + fov * M_PI / 180);
		ray.dir.y = sin(data->player.angle + fov * M_PI / 180);
		while (i < data->edge_nb)
		{
			pt = cast_ray_to_edge(ray, data->edges[i]);
			if (pt.x != -1 && pt.y != -1)
			{
				d = sqrt((pt.x - ray.pos.x) * (pt.x - ray.pos.x) + (pt.y - ray.pos.y) * (pt.y - ray.pos.y));
				if (d < record)
				{
					record = d;
					closest.x = pt.x;
					closest.y = pt.y;
				}
			}
			i++;
		}
		scene[j] = record* cos( fov * M_PI / 180);
		j++;
		// drawline(ray.pos, closest, data, 0);
		fov += fov_precision;
	}
	double w;
	int sSq;
	int wSq;
	int color;
	int h;
	int x;
	w = SCREEN_WIDTH / (data->player.fov / fov_precision);
	// printf("W:%f, pix_nb:%f\n", w, (data->player.fov / fov_precision));
	j = 0;
	while (j < data->player.fov / fov_precision)
	{
		sSq = scene[j] * scene[j];
		wSq = SCREEN_WIDTH * SCREEN_WIDTH;
		color = map(sSq, (t_point){0, wSq}, (t_point){255, 0});
		h = map(scene[j], (t_point){0, SCREEN_WIDTH}, (t_point){SCREEN_HEIGHT, 0});
		if (h > SCREEN_HEIGHT)
			h = SCREEN_HEIGHT;
		x = 0;
		while (x < w)
		{
			drawline((t_point){j * w + x, 0}, (t_point){j * w + x, SCREEN_HEIGHT / 2 - h / 2}, data, 0x87CEEB);
			drawline((t_point){j * w + x, SCREEN_HEIGHT / 2 - h / 2}, (t_point){j * w + x, SCREEN_HEIGHT / 2 + h / 2}, data, (color + 256* color + 256*256*color));
			drawline((t_point){j * w + x, SCREEN_HEIGHT / 2 + h / 2}, (t_point){j * w + x, SCREEN_HEIGHT}, data, 0x228B22);
			x++;
		}
		j++;
	}
	free(scene);
}
