/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_create.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/23 20:38:56 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 11:29:10 by naplouvi    ###    #+. /#+    ###.fr     */
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
	if ((map->tab = malloc(sizeof(char *) * (map->height + 1))) == NULL ||
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
