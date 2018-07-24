/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_create.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/23 20:38:56 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/24 05:20:38 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_do_map(t_map *map, char *argv, int x)
{
	int		i;
	int		j;
	int		fd;
	char	buf;
	char	**tab;

	map->width = x;
	i = 0;
	j = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return ;
	if ((tab = (char**)malloc(sizeof(char *) * (map->height + 1))) == NULL)
		return ;
	while (i < (map->height + 1))
	{
		if ((tab[i] = (char*)malloc(sizeof(char) * (map->width + 1))) == NULL)
			return ;
		while (read(fd, &buf, 1))
		{
			if (buf == '\n')
			{
				tab[i][j] = buf;
				tab[i][j + 1] = '\0';
				j = 0;
				i++;
				break ;
			}
			else
			{
				tab[i][j] = buf;
				j++;
			}
		}
	}
	tab[i] = NULL;
	ft_display_map(map);
}

void	ft_display_map(t_map *map)
{
	map->height = 0;
	ft_putstr("Je peux afficher la map ! \n");
}
