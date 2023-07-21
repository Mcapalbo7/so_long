/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:50:14 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/05/28 17:50:14 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *path)
{
	char	*tmp_map_first;
	char	*tmp_map;
	int		fd;
	char	**map;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	tmp_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp_map_first = tmp_map;
		tmp_map = ft_strjoin(tmp_map_first, line);
		free (line);
		free (tmp_map_first);
	}
	map = ft_split(tmp_map, '\n');
	free (tmp_map);
	close (fd);
	return (map);
}
