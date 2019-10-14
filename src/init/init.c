/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:37:54 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/14 19:15:55 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

short create_renderer_texture_and_pixels(t_data *data)
{
	if (!(data->renderer = SDL_CreateRenderer(data->window, -1, 0)))
	{
		ft_putstr_fd("Failed to create renderer! Error:", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (0);
	}
	else if (!(data->texture = SDL_CreateTexture(data->renderer,
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH,
		SCREEN_HEIGHT)))
	{
		ft_putstr_fd("Failed to create texture! Error:", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (0);
	}
	else if (!(data->pixels = (Uint32 *)malloc(sizeof(Uint32) * SCREEN_WIDTH
		* SCREEN_HEIGHT + 1)))
	{
		ft_putendl_fd("Failed to allocate pixels", 2);
		return (0);
	}
	return (1);
}

void set_values(t_data *data)
{
	data->player.pos.x = 1;
	data->player.pos.y = 1 ;
	data->box_length = 16;
	data->player.screen_pos.x = data->player.pos.x * 16 + data->box_length / 2;
	data->player.screen_pos.y = data->player.pos.y * 16 + data->box_length / 2;
	data->player.angle = 90 * M_PI / 180;
	data->player.fov = 60;
	data->player.dir.x = 0;
	data->player.dir.y = 1;
	data->player.plane.x = 0;
	data->player.plane.y = -1;
	data->player.rotSpeed = 0.01;
	data->player.walkSpeed = 0.5;
	data->edge_nb = 0;
	data->edges = NULL;
	data->texture = NULL;
	data->renderer = NULL;
	data->window = NULL;
	data->mapSize.x = 0;
	data->mapSize.y = 0;
	data->quit = 0;
}

short init(t_data *data)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_putstr_fd("Failed to initialize! Error:", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (0);
	}
	else
	{
		data->window = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_UNDEFINED,
										SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (data->window)
		{
			if (!create_renderer_texture_and_pixels(data))
				return (0);
		}
		else
		{
			ft_putstr_fd("Failed to create window! Error:", 2);
			ft_putendl_fd(SDL_GetError(), 2);
			return (0);
		}
	}
	return (1);
}
