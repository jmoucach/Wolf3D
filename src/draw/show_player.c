/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 11:55:03 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/08 16:29:17 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/wolf3d.h"

void			show_player(t_data *data, t_point length)
{
	Uint32		*pix;
	t_point		pt;
	t_d_point	dir;

	pt.x = data->p.pos.y * length.x;
	pt.y = data->p.pos.x * length.y;
	dir.y = data->p.dir.x * 10;
	dir.x = data->p.dir.y * 10;
	pix = data->pixels;
	drawline(pt, (t_point){pt.x + dir.x, pt.y + dir.y }, data, 0);
	pix[pt.x + pt.y * SCREEN_WIDTH] = 0xff00;
	pix[pt.x + 1 + pt.y * SCREEN_WIDTH] = 0xff00;
	pix[pt.x + 1 + (pt.y + 1) * SCREEN_WIDTH] = 0xff00;
	pix[pt.x + 1 + (pt.y - 1) * SCREEN_WIDTH] = 0xff00;
	pix[pt.x - 1 + (pt.y + 1) * SCREEN_WIDTH] = 0xff00;
	pix[pt.x - 1 + (pt.y - 1) * SCREEN_WIDTH] = 0xff00;
	pix[pt.x + (pt.y + 1) * SCREEN_WIDTH] = 0xff00;
	pix[pt.x - 1 + pt.y * SCREEN_WIDTH] = 0xff00;
	pix[pt.x + (pt.y - 1) * SCREEN_WIDTH] = 0xff00;
}
