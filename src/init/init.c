/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:37:54 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/22 15:11:04 by jmoucach         ###   ########->fr       */
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
	else if (!(data->pixels = (Uint32 *)malloc(sizeof(Uint32) * SCREEN_WIDTH * SCREEN_HEIGHT + 1)))
	{
		ft_putendl_fd("Failed to allocate pixels", 2);
		return (0);
	}
	return (1);
}

void set_raycast_values(t_raycast *values, t_player player, int x)
{
	values->camera = 2 * x / (double)SCREEN_WIDTH - 1;
	values->ray.pos.x = player.pos.x;
	values->ray.pos.y = player.pos.y;
	values->ray.dir.x = player.dir.x + player.plane.x * values->camera;
	values->ray.dir.y = player.dir.y + player.plane.y * values->camera;
	values->m_pos.x = (int)values->ray.pos.x;
	values->m_pos.y = (int)values->ray.pos.y;
	values->deltadist.x = sqrt(1 + (values->ray.dir.y * values->ray.dir.y) / (values->ray.dir.x * values->ray.dir.x));
	values->deltadist.y = sqrt(1 + (values->ray.dir.x * values->ray.dir.x) / (values->ray.dir.y * values->ray.dir.y));
	values->hit = 0;
	values->side = 0;
}

void set_values(t_data *data)
{
	data->box_length = 16;
	data->player.screen_pos.x = data->player.pos.x * 16 + data->box_length / 2;
	data->player.screen_pos.y = data->player.pos.y * 16 + data->box_length / 2;
	data->player.angle = 0 * M_PI / 180;
	data->player.fov = 30;
	data->player.dir.x = 1;
	data->player.dir.y = 0;
	data->player.plane.x = 0;
	data->player.plane.y = -0.66;
	data->player.rotationSpeed = 0.05;
	data->player.walkSpeed = 0.075;
	data->edge_nb = 0;
	data->edges = NULL;
	data->texture = NULL;
	data->renderer = NULL;
	data->window = NULL;
	data->mapSize.x = 0;
	data->mapSize.y = 0;
	data->quit = 0;
	if (!(data->surface = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 4)))
		exit(EXIT_FAILURE);
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
