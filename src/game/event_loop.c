/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:07:10 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/05 07:28:50 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void			handle_input2(t_data *data, const Uint8 *state)
{
	if (state[SDL_SCANCODE_M])
	{
		data->toggle_minimap = !data->toggle_minimap;
		SDL_Delay(50);
	}
}

void			handle_input(t_data *data, const Uint8 *state)
{
	if (state[SDL_SCANCODE_ESCAPE])
		data->quit = 1;
	if (state[SDL_SCANCODE_UP])
	{
		if (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT])
			sprint(data, 1);
		else
			walk(data, 1);
	}
	if (state[SDL_SCANCODE_DOWN])
	{
		if (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT])
			sprint(data, -1);
		else
			walk(data, -1);
	}
	if (state[SDL_SCANCODE_RIGHT])
		strafe(data, 1);
	if (state[SDL_SCANCODE_LEFT])
		strafe(data, -1);
	if (state[SDL_SCANCODE_A])
		rotate(data, 1);
	if (state[SDL_SCANCODE_D])
		rotate(data, -1);
	handle_input2(data, state);
}

void			handle_mouse(t_data *data)
{
	int			dir;

	dir = SCREEN_WIDTH/2;
	SDL_GetRelativeMouseState(&dir, NULL);
	if (dir > 0)
		dir = 1;
	else if (dir < 0)
		dir = -1;
	else
		dir = 0;
	if (dir != 0)
		rotate(data, -dir);
	SDL_WarpMouseInWindow(data->window, SCREEN_WIDTH /2, SCREEN_HEIGHT /2);
}

void			game_loop(t_data *data)
{
	const Uint8	*state;
	int			width;
	double		time;
	width = SCREEN_WIDTH;
	SDL_SetRelativeMouseMode(SDL_TRUE);
	while (!data->quit)
	{
		time = SDL_GetTicks();
		raycasting(data);
		if (data->toggle_minimap)
			draw_minimap(data);
		data->ftime = (SDL_GetTicks() - time) / 1000;
		handle_mouse(data);
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
