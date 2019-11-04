/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_edge_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:17:26 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/01 16:52:58 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

t_edge_list		*create_edge_list(t_point pt1, t_point pt2, int id)
{
	t_edge_list	*edge_list;

	if (!(edge_list = (t_edge_list *)malloc(sizeof(t_edge_list))))
		return (NULL);
	edge_list->id = id;
	edge_list->edge.start.x = pt1.x;
	edge_list->edge.start.y = pt1.y;
	edge_list->edge.end.x = pt2.x;
	edge_list->edge.end.y = pt2.y;
	edge_list->next = NULL;
	return (edge_list);
}
