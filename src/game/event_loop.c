/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:48:43 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/10 16:33:50 by jmoucach         ###   ########.fr       */
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
					if (data->map[(int)(data->player.pos.y + data->player.dir.y)][(int)(data->player.pos.x + data->player.dir.x)].value == 0)
					{
						data->player.pos.x += data->player.dir.x;
						data->player.pos.y += data->player.dir.y;
						data->player.screen_pos.x += data->box_length * data->player.dir.x;
						data->player.screen_pos.y += data->box_length * data->player.dir.y;
					}
				}

				if (data->event.key.keysym.sym == SDLK_DOWN)
				{
					if (data->map[(int)(data->player.pos.y - data->player.dir.y)][(int)(data->player.pos.x - data->player.dir.x)].value == 0)
					{
						data->player.pos.x -= data->player.dir.x;
						data->player.pos.y -= data->player.dir.y;
						data->player.screen_pos.x -= data->box_length * data->player.dir.x;
						data->player.screen_pos.y -= data->box_length * data->player.dir.y;
					}
				}

				// if (data->event.key.keysym.sym == SDLK_RIGHT)
				// {
				// 	if (data->map[(int)(data->player.pos.y + data->player.dir.y)][(int)(data->player.pos.x + data->player.dir.y)].value == 0)
				// 	{
				// 		data->player.pos.x += 1;
				// 		data->player.screen_pos.x += data->box_length * data->player.dir.y;
				// 		data->player.screen_pos.y += data->box_length * data->player.dir.x;
				// 	}
				// }

				// if (data->event.key.keysym.sym == SDLK_LEFT)
				// {
				// 	if (data->map[(int)(data->player.pos.y - data->player.dir.x)][(int)(data->player.pos.x - data->player.dir.y)].value == 0)
				// 	{
				// 		data->player.pos.x -= 1;
				// 	}
				// }
				if (data->event.key.keysym.sym == SDLK_a)// rotate to the left with 'A' key
				{
					data->player.angle -= 5* M_PI / 180;
					if (data->player.angle < 0)
						data->player.angle = M_PI * 2 - M_PI/180;
					data->player.dir.x = cos(-data->player.angle);
					data->player.dir.y = sin(-data->player.angle);
					printf("dir X:%f, Y:%f\n", data->player.dir.x, data->player.dir.y);
				}
				if (data->event.key.keysym.sym == SDLK_d) // rotate to the left with 'A' key
				{
					data->player.angle +=  5* M_PI / 180;
					if (data->player.angle > M_PI * 2 - M_PI/180)
						data->player.angle = 0;
					data->player.dir.x = cos(data->player.angle);
					data->player.dir.y = sin(data->player.angle);
					printf("dir X:%f, Y:%f\n", data->player.dir.x, data->player.dir.y);
				}
			}
		}
		// cast_ray(data);
		draw_map_box(data);
		show_player(data);
		SDL_UpdateTexture(data->texture, NULL, data->pixels, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(data->renderer);
		SDL_RenderCopy(data->renderer, data->texture, NULL, NULL);
		SDL_RenderPresent(data->renderer);
		ft_bzero(data->pixels, (SCREEN_WIDTH * SCREEN_HEIGHT + 1) * 4);
		time = SDL_GetTicks();
	}
}
