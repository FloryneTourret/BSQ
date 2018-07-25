/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_resolver.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 19:15:41 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 20:38:16 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/header.h"

int		resolve_map_1(t_map *map, int *square, int *i, int *j)
{
	(*i) = 0;
	(*j) = -1;
	(*square) = map->height > map->width ? map->width : map->height;
	if (map->height == 1 && map->width == 1)
	{
		if (map->tab[1][0] == map->empty)
			ft_putchar(map->sqr);
		else
			ft_putchar(map->obs);
		ft_putchar('\n');
		return (0);
	}
	return (1);
}

int		ft_check_display(t_map *map, int i, int j, int square)
{
	if (((map->tab[i][j] == map->empty)
		&& (ft_check_square(map, i, j, square) == 0))
		|| (i == map->height && j == map->width - 1))
	{
		ft_display_map(map);
		return (0);
	}
	return (1);
}

int		ft_resolve_map(t_map *map)
{
	int	square;
	int i;
	int j;

	if (resolve_map_1(map, &square, &i, &j) == 1)
	{
		while (square >= 0)
		{
			while (++i < map->height + 1 && map->tab[i + square])
			{
				while (map->tab[i][++j] != '\n' && map->tab[i][j + square])
				{
					if (ft_check_display(map, i, j, square) == 0)
						return (0);
				}
				j = -1;
			}
			i = 0;
			square--;
		}
	}
	return (1);
}

int		ft_check_square(t_map *map, int i, int j, int square)
{
	int	limit_i;
	int limit_j;
	int	k;

	limit_i = i + square;
	limit_j = j + square;
	k = j;
	while (i <= limit_i)
	{
		j = k;
		while (j <= limit_j)
		{
			if (map->tab[i][j] == map->obs || map->tab[i][j] == '\n')
				return (1);
			j++;
		}
		i++;
	}
	i = limit_i - square;
	j = limit_j - square;
	ft_square_found(map, i, j, square);
	return (0);
}

void	ft_square_found(t_map *map, int i, int j, int square)
{
	int	limit_i;
	int limit_j;
	int	k;

	limit_i = i + square - 1;
	limit_j = j + square;
	k = j;
	while (i <= limit_i + 1)
	{
		j = k;
		while (j <= limit_j)
		{
			if (map->tab[i][j] == map->empty && map->tab[i][j] != '\n')
				map->tab[i][j] = map->sqr;
			j++;
		}
		i++;
	}
}
