/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_display.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/24 17:00:51 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 18:58:19 by naplouvi    ###    #+. /#+    ###.fr     */
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
