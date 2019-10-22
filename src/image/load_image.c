/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:42:14 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/22 15:46:32 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

Uint32 get_pixel(SDL_Surface *s, int x, int y)
{
	int bpp;
	Uint8 *p;

	bpp =s->format->BytesPerPixel;
	p= s->pixels + y*s->pitch + x*bpp;

	if (bpp ==1)
		return *p;
	else if (bpp == 2)
		return *(Uint16*)p;
	else if (bpp == 3)
		return ((p[0]) | (p[1] << 8) | (p[2]<<16));
	else
		return *(Uint32*)p;
}

void draw_texture(t_data *data, int index, int xoff, int yoff)
{
	int x;
	int y;
	Uint32 *pix;
	Uint32 color;
	Uint32 *surface_pixels;

	if (SDL_MUSTLOCK(data->surface[index]))
		SDL_LockSurface(data->surface[index]);
	surface_pixels = (Uint32*)data->surface[index]->pixels;
	pix = data->pixels;
	y =0;
	while (y <data->surface[index]->h)
	{
		x=0;
		while (x<data->surface[index]->w)
		{
			color = get_pixel(data->surface[index],x, y);
			pix[x * 2 + xoff + (y * 2+yoff) *SCREEN_WIDTH] =color;
			pix[(x * 2) + xoff + ((y * 2)+ 1+yoff) *SCREEN_WIDTH] =color;
			pix[(x * 2) + xoff + ((y * 2)+ 1+yoff) *SCREEN_WIDTH] =color;
			pix[(x * 2) + 1 + xoff + ((y * 2)+ 1+yoff) *SCREEN_WIDTH] =color;
			pix[(x * 2) + 1 + xoff + ((y * 2)+yoff) *SCREEN_WIDTH] =color;;
			x++;
		}
		y++;
	}
	if (SDL_MUSTLOCK(data->surface[index]))
		SDL_UnlockSurface(data->surface[index]);
}

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
