/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_resolver.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/24 16:49:59 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/24 20:55:22 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_resolve_map(t_map *map)
{
	int	square;
	int i;
	int j;

	i = 1;
	j = 0;
	square = map->height > map->width ? map->width : map->height;
	while (square > 0)
	{
		while (++i < map->height && map->tab[i + square - 1])
		{
			while (map->tab[i][++j] != '\n' && map->tab[i][j + square - 1])
			{
				if ((map->tab[i][j] == map->empty) &&
				(ft_check_square(map, i, j, square) == 0))
					ft_display_map(map);
			}
			j = 0;
		}
		i = 0;
		square--;
	}
}

int		ft_check_square(t_map *map, int i, int j, int square)
{
	int	limit_i;
	int limit_j;

	limit_i = i + square;
	limit_j = j + square;
	while (i < limit_i)
	{
		j = 0;
		while (j < limit_j)
		{
			if (map->tab[i][j] == map->obs)
				return (1);
			j++;
		}
		i++;
	}
	ft_square_found(map, limit_i, limit_j, square);
	return (0);
}

void	ft_square_found(t_map *map, int limit_i, int limit_j, int square)
{
	int	i;
	int j;

	i = limit_i - square;
	j = limit_j - square - 1;
	while (i <= limit_i)
	{
		while (j < limit_j)
		{
			if (map->tab[i][j] == map->empty)
			{
				map->tab[i][j] = 'x';
				j++;
			}
		}
		j = 0;
		i++;
	}
}
