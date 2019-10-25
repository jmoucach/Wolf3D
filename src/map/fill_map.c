/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:51:49 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/25 09:23:16 by jmoucach         ###   ########.fr       */
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

short fill_map(t_data *data, char *str)
{
	int i;

	if (!parse_map(data, str))
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
		{
			data->player.pos.x = (i / 2) / data->mapSize.x + 0.5;
			data->player.pos.y = (i / 2) % data->mapSize.x + 0.5;

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
