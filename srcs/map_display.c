/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_display.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 19:15:29 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 19:15:32 by ftourret    ###    #+. /#+    ###.fr     */
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
	i = 0;
	free(map->tab);
}

void	print_error(void)
{
	write(2, "map error\n", 10);
}

void	print_close_error(void)
{
	write(2, "close error\n", 12);
}
