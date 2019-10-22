/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:51:49 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/22 18:00:15 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void print_map(t_data data)
{
	int i;
	int j;

	i = 0;
	while (i < data.mapSize.y)
	{
		j = 0;
		while (j < data.mapSize.x)
		{
			printf("%d, ", data.map[i][j].value);
			j++;
		}
		printf("\n");
		i++;
	}
}

short parse_map(char *str)
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

short fill_map(t_data *data, char *str)
{
	int i;

	if (!parse_map(str))
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
		{
			data->player.pos.x = (i / 2) / data->mapSize.x;
			data->player.pos.y = (i / 2) % data->mapSize.x;

			printf("player pos x:%f, y:%f\n", data->player.pos.x,data->player.pos.y);
			data->map[(i / 2) / data->mapSize.x][(i / 2) % data->mapSize.x].value = 0;
		}
		else if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3')
		{
			data->map[(i / 2) / data->mapSize.x][(i / 2) % data->mapSize.x].value = str[i] - '0';
		}
		i++;
	}
	return (1);
}
