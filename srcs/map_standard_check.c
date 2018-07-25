/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_standard_check.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 20:03:59 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 20:57:31 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_final_standard_check(t_map *map, char *argv, int x, int i)
{
	if (x <= 0)
		print_error();
	(map->height * x) != (i) ? print_error() : ft_do_standard_map(map, argv, x);
}

void	ft_check_standard_width(t_map *map, char *argv)
{
	int		i;
	int		y;
	int		x;
	int		j;

	y = 0;
	x = 0;
	i = 0;
	j = 0;
	while (argv[j])
	{
		if (y > 0 && (argv[j] == map->empty || argv[j] == map->obs ||
			argv[j] == map->sqr))
			i++;
		if (argv[j] == '\n' && y != map->height)
		{
			y++;
			x = 0;
		}
		if (argv[j] != '\n' && y > 0)
			x++;
		j++;
	}
	ft_final_standard_check(map, argv, x, i);
}

void	ft_check_standard_height(t_map *map, char *argv)
{
	int		y;
	int		j;

	y = 0;
	j = 0;
	while (argv[j])
	{
		if (argv[j] == '\n')
			y++;
		j++;
	}
	y--;
	if (y != map->height)
		print_error();
	else
		ft_check_standard_width(map, argv);
}

void	ft_create_standard_map(char *str, char *argv)
{
	int		i;
	char	height[BUF_SIZE];
	t_map	*map;
	int		nb;

	if ((map = malloc(sizeof(t_map))) == NULL)
		return ;
	i = 0;
	while (str[i + 1] != '\0')
		i++;
	map->sqr = str[i];
	map->obs = str[i - 1];
	map->empty = str[i - 2];
	i = -1;
	while (str[++i + 3] != '\0')
		height[i] = str[i];
	nb = ft_atoi(height);
	map->height = nb;
	ft_check_standard_height(map, argv);
}

int		ft_check_standard_map(char *argv)
{
	int		i;
	int		j;
	char	str[BUF_SIZE];

	j = 0;
	i = 0;
	while (argv[j])
	{
		if (argv[j] != '\n')
		{
			str[i] = argv[j];
			i++;
		}
		else
			break ;
		j++;
	}
	str[i] = '\0';
	ft_create_standard_map(str, argv);
	return (0);
}
