/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:07:10 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/08 16:29:17 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/wolf3d.h"

void			handle_input2(t_data *data, const Uint8 *state)
{
	if (state[SDL_SCANCODE_M])
	{
		data->toggle_minimap = !data->toggle_minimap;
		SDL_Delay(50);
	}
	if (state[SDL_SCANCODE_UP] && data->yaw < SCREEN_HEIGHT)
		data->yaw += 40;
	if (state[SDL_SCANCODE_DOWN] && data->yaw > -SCREEN_HEIGHT)
		data->yaw -= 40;
}

void			handle_input(t_data *data, const Uint8 *state)
{
	if (state[SDL_SCANCODE_ESCAPE])
		data->quit = 1;
	if (state[SDL_SCANCODE_W])
	{
		if (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT])
			sprint(data, 1);
		else
			walk(data, 1);
	}
	if (state[SDL_SCANCODE_S])
	{
		if (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT])
			sprint(data, -1);
		else
			walk(data, -1);
	}
	if (state[SDL_SCANCODE_D])
		strafe(data, 1);
	if (state[SDL_SCANCODE_A])
		strafe(data, -1);
	if (state[SDL_SCANCODE_LEFT])
		rotate(data, 1);
	if (state[SDL_SCANCODE_RIGHT])
		rotate(data, -1);
	handle_input2(data, state);
}

void			game_loop(t_data *data)
{
	const Uint8	*state;
	int			width;
	double		time;

	width = SCREEN_WIDTH;
	while (!data->quit)
	{
		time = SDL_GetTicks();
		raycasting(data);
		if (data->toggle_minimap)
			draw_minimap(data);
		data->ftime = (SDL_GetTicks() - time) / 1000;
		SDL_PumpEvents();
		state = SDL_GetKeyboardState(NULL);
		handle_input(data, state);
		SDL_UpdateTexture(data->texture, NULL, data->pixels,
			width * 4);
		SDL_RenderClear(data->renderer);
		SDL_RenderCopy(data->renderer, data->texture, NULL, NULL);
		SDL_RenderPresent(data->renderer);
		ft_bzero(data->pixels, (SCREEN_WIDTH * SCREEN_HEIGHT + 1) * 4);
	}
}
