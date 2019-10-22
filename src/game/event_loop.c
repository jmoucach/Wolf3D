/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:48:43 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/22 15:49:21 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void game_loop(t_data *data)
{
	double time;
	double deltaTime;
	time = SDL_GetTicks();
	while (!data->quit)
	{
		deltaTime = SDL_GetTicks() - time;

		while (SDL_PollEvent(&data->event))
		{
			if (data->event.type == SDL_QUIT)
				data->quit = 1;
			if (data->event.type == SDL_KEYDOWN)
			{
				if (data->event.key.keysym.sym == SDLK_ESCAPE)
					data->quit = 1;
				if (data->event.key.keysym.sym == SDLK_UP)
				{

					if (data->map[(int)(data->player.pos.x + data->player.dir.x * data->player.walkSpeed)][(int)(data->player.pos.y)].value == 0)
						data->player.pos.x += data->player.dir.x * data->player.walkSpeed;
					if (data->map[(int)(data->player.pos.x)][(int)(data->player.pos.y + data->player.dir.y * data->player.walkSpeed)].value == 0)
						data->player.pos.y += data->player.dir.y * data->player.walkSpeed;
					// 	if (data->map[(int)(data->player.pos.y + data->player.dir.y)][(int)(data->player.pos.x + data->player.dir.x)].value == 0)
					// 	{
					// 		data->player.pos.x += data->player.dir.x;
					// 		data->player.pos.y += data->player.dir.y;
					// 		data->player.screen_pos.x += data->box_length * data->player.dir.x;
					// 		data->player.screen_pos.y += data->box_length * data->player.dir.y;
					// 		// printf("pos:X:%f, Y:%f\n", data->player.pos.x *16,data->player.pos.y*16);
					// 	}
				}
				if (data->event.key.keysym.sym == SDLK_DOWN)
				{
					if (data->map[(int)(data->player.pos.x - data->player.dir.x * data->player.walkSpeed)][(int)data->player.pos.y].value == 0)
						data->player.pos.x -= data->player.dir.x * data->player.walkSpeed;
					if (data->map[(int)(data->player.pos.x)][(int)(data->player.pos.y - data->player.dir.y * data->player.walkSpeed)].value == 0)
						data->player.pos.y -= data->player.dir.y * data->player.walkSpeed;
					// if (data->map[(int)(data->player.pos.y - data->player.dir.y)][(int)(data->player.pos.x - data->player.dir.x)].value == 0)
					// {
					// 	data->player.pos.x -= data->player.dir.x;
					// 	data->player.pos.y -= data->player.dir.y;
					// 	data->player.screen_pos.x -= data->box_length * data->player.dir.x;
					// 	data->player.screen_pos.y -= data->box_length * data->player.dir.y;
					// 	// printf("pos:X:%f, Y:%f\n", data->player.pos.x *16,data->player.pos.y*16);
					// }
				}
				if (data->event.key.keysym.sym == SDLK_a) // rotate to the left with 'A' key
				{

					double oldDirX = data->player.dir.x;
					data->player.dir.x = data->player.dir.x * cos(data->player.rotationSpeed) - data->player.dir.y * sin(data->player.rotationSpeed);
					data->player.dir.y = oldDirX * sin(data->player.rotationSpeed) + data->player.dir.y * cos(data->player.rotationSpeed);

					double oldPlaneX = data->player.plane.x;
					data->player.plane.x = data->player.plane.x * cos(data->player.rotationSpeed) - data->player.plane.y * sin(data->player.rotationSpeed);
					data->player.plane.y = oldPlaneX * sin(data->player.rotationSpeed) + data->player.plane.y * cos(data->player.rotationSpeed);
					// data->player.angle -= 2* M_PI / 180;
					// if (data->player.angle < -M_PI)
					// 	data->player.angle = M_PI;
					// data->player.dir.x = cos(data->player.angle);
					// data->player.dir.y = sin(data->player.angle);
					// printf("angle:%f\n", data->player.angle* 180 / M_PI);
					// printf("dir X:%f, Y:%f\n", data->player.dir.x, data->player.dir.y);
				}
				if (data->event.key.keysym.sym == SDLK_d) // rotate to the left with 'A' key
				{

					double oldDirX = data->player.dir.x;
					data->player.dir.x = data->player.dir.x * cos(-data->player.rotationSpeed) - data->player.dir.y * sin(-data->player.rotationSpeed);
					data->player.dir.y = oldDirX * sin(-data->player.rotationSpeed) + data->player.dir.y * cos(-data->player.rotationSpeed);

					double oldPlaneX = data->player.plane.x;
					data->player.plane.x = data->player.plane.x * cos(-data->player.rotationSpeed) - data->player.plane.y * sin(-data->player.rotationSpeed);
					data->player.plane.y = oldPlaneX * sin(-data->player.rotationSpeed) + data->player.plane.y * cos(-data->player.rotationSpeed);
					// data->player.angle +=  2* M_PI / 180;
					// if (data->player.angle > M_PI)
					// 	data->player.angle = -M_PI;
					// data->player.dir.x = cos(data->player.angle);
					// data->player.dir.y = sin(data->player.angle);
					// printf("angle:%f\n", data->player.angle* 180 / M_PI);
					// printf("dir X:%f, Y:%f\n", data->player.dir.x, data->player.dir.y);
				}
				// if (data->event.key.keysym.sym == SDLK_q) // rotate to the left with 'A' key
				// {
				// 	data->player.angle -= M_PI_2;
				// 	if (data->player.angle < -M_PI + 1)
				// 		data->player.angle = M_PI;
				// 	data->player.dir.x = cos(data->player.angle);
				// 	data->player.dir.y = sin(data->player.angle);
				// 	// printf("angle:%f\n", data->player.angle* 180 / M_PI);
				// 	// printf("dir X:%f, Y:%f\n", data->player.dir.x, data->player.dir.y);
				// }
				// if (data->event.key.keysym.sym == SDLK_e) // rotate to the left with 'A' key
				// {
				// 	data->player.angle += M_PI_2;
				// 	if (data->player.angle > M_PI - 1)
				// 		// data->player.angle = -M_PI;
				// 	// data->player.dir.x = cos(data->player.angle);
				// 	// data->player.dir.y = sin(data->player.angle);
				// 	// printf("angle:%f\n", data->player.angle * 180 / M_PI);
				// 	// printf("dir X:%f, Y:%f\n", data->player.dir.x, data->player.dir.y);
				// }
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
