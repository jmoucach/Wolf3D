/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_edges_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:29:08 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/14 12:39:24 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void 	print_edges_array(t_data *data)
{
	int i;

	i = 0;
	while (i < data->edge_nb)
	{
		printf("i:%d |Start:X:%d Y:%d, End:X:%d Y:%d|\n",i, data->edges[i].start.x,data->edges[i].start.y,data->edges[i].end.x,data->edges[i].end.y);
		i++;
	}
}
