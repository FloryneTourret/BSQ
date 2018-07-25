/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_display.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/24 17:00:51 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 11:21:50 by naplouvi    ###    #+. /#+    ###.fr     */
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
	exit(0);
}

void	print_error(void)
{
	write(2, "map error\n", 10);
	exit(1);
}

void	print_close_error(void)
{
	write(2, "close error\n", 12);
	exit(1);
}
