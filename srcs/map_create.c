/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_create.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 19:15:09 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 19:15:11 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/header.h"

int		ft_char_to_tab(char **tab, char buf, int *i, int *j)
{
	if (buf == '\n')
	{
		tab[*i][*j] = buf;
		tab[*i][*j + 1] = '\0';
		*j = 0;
		(*i)++;
		return (0);
	}
	else
	{
		tab[*i][*j] = buf;
		(*j)++;
	}
	return (1);
}

void	ft_do_map(t_map *map, char *argv, int x)
{
	int		i;
	int		j;
	int		fd;
	char	buf;

	map->width = x;
	i = 0;
	j = 0;
	fd = open(argv, O_RDONLY);
	map->tab = NULL;
	if ((map->tab = malloc(sizeof(char *) * (map->height + 2))) == NULL ||
		fd == -1)
		return ;
	while (i < (map->height + 1))
	{
		if ((map->tab[i] = malloc(sizeof(char) * (map->width + 1))) == NULL)
			return ;
		while (read(fd, &buf, 1))
		{
			if (ft_char_to_tab(map->tab, buf, &i, &j) == 0)
				break ;
		}
	}
	map->tab[i] = NULL;
	close(fd) == -1 ? print_close_error() : ft_resolve_map(map);
}
