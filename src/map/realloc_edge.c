/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_edge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:27:54 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/07 11:54:39 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void 	realloc_edge(t_data *data)
{
	t_edge *tmp;
	int i;

	i = 0;
	tmp = data->edges;
	if (!(data->edges = (t_edge *)malloc(sizeof(t_edge) * data->edge_nb)))
		return ;
	while (++i < data->edge_nb - 1)
		copy_edge_data(&data->edges, tmp, i);
	 free(tmp);
}
