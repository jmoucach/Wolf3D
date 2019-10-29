/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 09:15:24 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/25 09:48:53 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

short parse_char(char *str)
{
	int i;
	int p_num;

	i = 0;
	p_num = 0;
	while (str[i])
	{
		if (str[i] == 'P')
		{
			p_num++;
		}
		else if (str[i] != '0' && str[i] != '1' && str[i] != ',' && str[i] != '2' && str[i] != '3')
		{
			ft_putendl_fd("Invalid map data", 2);
			return (0);
		}
		i++;
	}
	if (p_num != 1)
		{
			ft_putendl_fd("Invalid number of player", 2);
			return (0);
		}
	return (1);
}

short parse_boudaries(char *str, t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->mapSize.y)
	{
		if (str[2*(y * data->mapSize.x)] == '0' || str[2*(y * data->mapSize.x
			+ data->mapSize.x - 1)] == '0')
			return (0);
		y ++;
	}
	x = 0;
	while (x < data->mapSize.x)
	{
		if (str[2*x] == '0' || str[2*(x + (data->mapSize.y-1)*data->mapSize.x)] == '0')
			return (0);
		x++;
	}
	return (1);
}

short parse_map(t_data *data, char *str)
{
	if (parse_char(str) && parse_boudaries(str, data))
		return (1);
	else
	{
		ft_putendl_fd("Incomplete Boundaries", 2);
		return (0);
	}
}