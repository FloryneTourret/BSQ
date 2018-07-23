/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_create.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/23 20:38:56 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/23 20:45:03 by naplouvi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_do_map(t_map *map, char *argv, int x)
{
	map->width = x;

	ft_putchar(map->empty);
	ft_putchar(map->obs);
	ft_putchar(map->sqr);
	ft_putnbr(map->height);
	ft_putnbr(map->width);
}
