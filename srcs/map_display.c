/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_display.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/24 17:00:51 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/24 17:40:36 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_display_map(t_map *map)
{
	int		i;

	i = 1;
	while (map->tab[i])
	{
		ft_putstr(map->tab[i]);
		i++;
	}
	exit(101);
}

void	print_error(void)
{
	write(2, "map error\n", 10);
	exit(1);
}
