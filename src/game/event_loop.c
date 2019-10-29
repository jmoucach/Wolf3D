/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:48:43 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/29 18:34:56 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void game_loop(t_data *data)
{
	double time;
	const Uint8 *state;
	double deltaTime;
	time = SDL_GetTicks();
	while (!data->quit)
	{
		deltaTime = SDL_GetTicks() - time;
		state = SDL_GetKeyboardState(NULL);
		while (SDL_PollEvent(&data->event))
		{
			if (data->event.type == SDL_QUIT)
				data->quit = 1;
			if (data->event.type == SDL_KEYDOWN)
			{
				if (state[SDL_SCANCODE_ESCAPE])
					data->quit = 1;
				if (state[SDL_SCANCODE_UP])
				{

					if (data->map[(int)(data->player.pos.x + data->player.dir.x * data->player.walkSpeed)][(int)(data->player.pos.y)].value == 0)
						data->player.pos.x += data->player.dir.x * data->player.walkSpeed;
					if (data->map[(int)(data->player.pos.x)][(int)(data->player.pos.y + data->player.dir.y * data->player.walkSpeed)].value == 0)
						data->player.pos.y += data->player.dir.y * data->player.walkSpeed;
				}
				if (state[SDL_SCANCODE_DOWN])
				{
					if (data->map[(int)(data->player.pos.x - data->player.dir.x * data->player.walkSpeed)][(int)data->player.pos.y].value == 0)
						data->player.pos.x -= data->player.dir.x * data->player.walkSpeed;
					if (data->map[(int)(data->player.pos.x)][(int)(data->player.pos.y - data->player.dir.y * data->player.walkSpeed)].value == 0)
						data->player.pos.y -= data->player.dir.y * data->player.walkSpeed;
				}
				if (state[SDL_SCANCODE_RIGHT])
				{
					if (data->map[(int)(data->player.pos.x + data->player.dir.y * data->player.walkSpeed)][(int)data->player.pos.y].value == 0)
						data->player.pos.x += data->player.dir.y * data->player.walkSpeed;
					if (data->map[(int)(data->player.pos.x)][(int)(data->player.pos.y - data->player.dir.x * data->player.walkSpeed)].value == 0)
						data->player.pos.y -= data->player.dir.x * data->player.walkSpeed;
				}
				if (state[SDL_SCANCODE_LEFT])
				{
					if (data->map[(int)(data->player.pos.x - data->player.dir.y * data->player.walkSpeed)][(int)data->player.pos.y].value == 0)
						data->player.pos.x -= data->player.dir.y * data->player.walkSpeed;
					if (data->map[(int)(data->player.pos.x)][(int)(data->player.pos.y + data->player.dir.x * data->player.walkSpeed)].value == 0)
						data->player.pos.y += data->player.dir.x * data->player.walkSpeed;
				}
				if (state[SDL_SCANCODE_A])
				{
					double oldDirX = data->player.dir.x;
					data->player.dir.x = data->player.dir.x * cos(data->player.rotationSpeed) - data->player.dir.y * sin(data->player.rotationSpeed);
					data->player.dir.y = oldDirX * sin(data->player.rotationSpeed) + data->player.dir.y * cos(data->player.rotationSpeed);

					// printf("dir:X:%f, Y:%f\n", data->player.dir.x, data->player.dir.y);
					double oldPlaneX = data->player.plane.x;
					data->player.plane.x = data->player.plane.x * cos(data->player.rotationSpeed) - data->player.plane.y * sin(data->player.rotationSpeed);
					data->player.plane.y = oldPlaneX * sin(data->player.rotationSpeed) + data->player.plane.y * cos(data->player.rotationSpeed);
				}
				if (state[SDL_SCANCODE_D]) // rotate to the left with 'A' key
				{

					double oldDirX = data->player.dir.x;
					data->player.dir.x = data->player.dir.x * cos(-data->player.rotationSpeed) - data->player.dir.y * sin(-data->player.rotationSpeed);
					data->player.dir.y = oldDirX * sin(-data->player.rotationSpeed) + data->player.dir.y * cos(-data->player.rotationSpeed);
					// printf("dir:X:%f, Y:%f\n", data->player.dir.x, data->player.dir.y);

					double oldPlaneX = data->player.plane.x;
					data->player.plane.x = data->player.plane.x * cos(-data->player.rotationSpeed) - data->player.plane.y * sin(-data->player.rotationSpeed);
					data->player.plane.y = oldPlaneX * sin(-data->player.rotationSpeed) + data->player.plane.y * cos(-data->player.rotationSpeed);
				}
			}
		}
		// draw_map_box(data);
		// show_player(data);
		// raycast(data);
		raycasting2(data);
		// draw_texture(data, 0, 0, 0);
		SDL_UpdateTexture(data->texture, NULL, data->pixels, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(data->renderer);
		SDL_RenderCopy(data->renderer, data->texture, NULL, NULL);
		SDL_RenderPresent(data->renderer);
		ft_bzero(data->pixels, (SCREEN_WIDTH * SCREEN_HEIGHT + 1) * 4);
		// while (1);
		time = SDL_GetTicks();
		// break ;
	}
}
