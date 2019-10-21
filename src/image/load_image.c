/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:42:14 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/21 10:45:19 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"


SDL_Surface *loadImage(char *path)
{
	SDL_Surface *loadedSurface;
	loadedSurface = SDL_LoadBMP(path);
	if (!loadedSurface)
	{
		ft_putstr_fd("Couldn't load image:", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("Error :", 2);
		ft_putendl_fd(SDL_GetError(), 2);
	}
	return (loadedSurface);
}

short loadMedia(t_data *data)
{
	data->surface[0] = loadImage("pics/redbrick.bmp");
	if (!data->surface[0])
		return (0);
	data->surface[1] = loadImage("pics/eagle.bmp");
	if (!data->surface[1])
		return (0);
	data->surface[2] = loadImage("pics/wood.bmp");
	if (!data->surface[2])
		return (0);
	data->surface[3] = loadImage("pics/mossy.bmp");
	if (!data->surface[3])
		return (0);
	return (1);
}
