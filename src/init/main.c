/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:14:06 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/01 18:02:18 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void	free_map(t_data *data)
{
	int i;

	i = data->msize.y;
	while (--i >= 0)
		free(data->map[i]);
	free(data->map);
}

void	close_all(t_data *data)
{
	if (data->pixels)
		free(data->pixels);
	if (data->texture)
		SDL_DestroyTexture(data->texture);
	if (data->renderer)
		SDL_DestroyRenderer(data->renderer);
	if (data->window)
		SDL_DestroyWindow(data->window);
	SDL_Quit();
}

int		main(int ac, char **av)
{
	t_data data;

	if (ac == 2)
	{
		set_values(&data);
		if (init(&data))
		{
			if (loadmedia(&data))
			{
				if (new_map(&data, av[1]))
				{
					game_loop(&data);
					free_map(&data);
				}
				close_all(&data);
			}
		}
		else
		{
			ft_putstr_fd("Error in initialization!", 2);
		}
	}
	return (1);
}
