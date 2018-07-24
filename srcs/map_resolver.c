/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_resolver.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/24 16:49:59 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/24 18:33:30 by ftourret    ###    #+. /#+    ###.fr     */
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
	while (square >= 1)
	{
		ft_putnbr(square);
		ft_putchar('\n');
		while (map->tab[i][j] != '\n')
		{
			if (map->tab[i][j] == map->obs)
				j++;
			if (map->tab[i][j] == map->empty)
			{
				if (ft_check_square(map, i, j, square) == 0)
					ft_display_map(map);
				j++;
			}
		}
		j = 0;
		i++;
		square--;
	}
}

int		ft_check_square(t_map *map, int i, int j, int square)
{
	int	limit_i;
	int limit_j;

	limit_i = j + square - 1;
	limit_j = i + square - 1;
	while (i <= limit_i)
	{
		while (j <= limit_j)
		{
			if (map->tab[i][j] == map->empty)
				j++;
			if (map->tab[i][j] == map->obs)
				return (1);
			if (j == limit_j)
			{
				j = 0;
				i++;
			}
		}
	}
	ft_square_found(map, limit_i, limit_j, square);
	return (0);
}

void	ft_square_found(t_map *map, int limit_i, int limit_j, int square)
{
	int	i;
	int j;

	i = limit_j - square + 1;
	j = limit_i - square + 1;
	ft_putstr("ligne : ");
	ft_putnbr(i);
	ft_putstr("\ncolonne : ");
	ft_putnbr(j);
	ft_putstr("\n");
	while (i <= limit_i)
	{
		while (j <= limit_j)
		{
			if (map->tab[i][j] == map->empty)
			{
				map->tab[i][j] = 'x';
				j++;
			}
			if (j == limit_j)
			{
				j = 0;
				i++;
			}
		}
	}
}