/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_edges_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:29:08 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/01 17:42:11 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void	print_edges_array(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->edge_nb)
	{
		ft_putstr("i:");
		ft_putnbr(i);
		ft_putstr(" |START:X:");
		ft_putnbr(data->edges[i].start.x);
		ft_putstr(" Y:");
		ft_putnbr(data->edges[i].start.y);
		ft_putstr(" END:X:");
		ft_putnbr(data->edges[i].end.x);
		ft_putstr(" Y:");
		ft_putnbr(data->edges[i].end.y);
		ft_putendl("|");
		i++;
	}
}
