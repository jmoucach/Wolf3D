/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_edge_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:21:54 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/12 18:23:39 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void	delete_edge_list(t_edge_list **edges)
{
	t_edge_list *tmp;

	while ((*edges)->next)
	{
		tmp = (*edges)->next;
		(*edges)->next = NULL;
		free(*edges);
		*edges = tmp;
	}
}
