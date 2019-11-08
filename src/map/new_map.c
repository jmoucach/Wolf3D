/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:46:23 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/08 18:04:18 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/wolf3d.h"

short			count_lines_and_col(t_data *data, char *str)
{
	int			i;
	int			tmp;
	int			col;

	i = -1;
	while (++i < (int)ft_strlen(str))
	{
		col = data->msize.x;
		data->msize.x = 0;
		tmp = 0;
		while (str[i] && str[i] != '\n')
		{
			if (tmp == 1 && str[i] == ',')
				tmp = 0;
			if (tmp == 0 && str[i] != ',')
				data->msize.x++;
			if (tmp == 0 && str[i] != ',')
				tmp = 1;
			i++;
		}
		if (data->msize.x != col && col != 0)
			return (0);
		data->msize.y++;
	}
	return (1);
}

char			*join_strings(char *s1, char *s2)
{
	char		*str;
	const int	l1 = (s1) ? ft_strlen(s1) : 0;
	const int	l2 = (s2) ? ft_strlen(s2) : 0;

	if (!(str = (char *)malloc(sizeof(char) * (l1 + l2 + 1))))
		return (NULL);
	ft_memcpy(str, s1, l1);
	ft_memcpy(str + l1, s2, l2);
	str[l1 + l2] = '\0';
	return (str);
}

char			*read_map(int fd)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*str;
	char		*tmp;

	str = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str;
		str = join_strings(tmp, buf);
		free(tmp);
	}
	if (ret == -1 || !str)
		return (NULL);
	return (str);
}

short			allocate_map(t_data *data)
{
	int			i;

	i = 0;
	if (!(data->map = (int**)malloc(sizeof(int*) * data->msize.y)))
		return (0);
	while (i < data->msize.y)
	{
		if (!(data->map[i] = (int*)malloc(sizeof(int) * data->msize.x)))
		{
			while (i-- >= 0)
				free(data->map[i]);
			free(data->map);
			return (0);
		}
		i++;
	}
	return (1);
}

short			new_map(t_data *data, char *title)
{
	int			fd;
	char		*str;

	fd = open(title, O_RDONLY);
	if (!(str = read_map(fd)))
		return (0);
	if (!count_lines_and_col(data, str))
		return (0);
	str = ft_replace(str, '\n', ',');
	close(fd);
	if (!allocate_map(data))
		return (0);
	if (!(fill_map(data, str)))
		return (0);
	free(str);
	print_map(*data);
	return (1);
}
