/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_check.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 19:14:59 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 19:24:18 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_final_check(t_map *map, char *argv, int x, int i)
{
	if (x <= 0)
		print_error();
	(map->height * x) != (i) ? print_error() : ft_do_map(map, argv, x);
}

void	ft_check_width(t_map *map, char *argv)
{
	int		i;
	int		y;
	int		x;
	int		fd;
	char	buf;

	y = 0;
	x = 0;
	i = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return ;
	while (read(fd, &buf, 1))
	{
		if (y > 0 && (buf == map->empty || buf == map->obs || buf == map->sqr))
			i++;
		if (buf == '\n' && y != map->height)
		{
			y++;
			x = 0;
		}
		if (buf != '\n' && y > 0)
			x++;
	}
	close(fd) == -1 ? print_close_error() : ft_final_check(map, argv, x, i);
}

void	ft_check_height(t_map *map, char *argv)
{
	int		y;
	int		fd;
	char	buf;

	y = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return ;
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			y++;
	}
	y--;
	if (close(fd) == -1)
		return ;
	if (y != map->height)
		print_error();
	ft_check_width(map, argv);
}

void	ft_create_map(char *str, char *argv)
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
	ft_check_height(map, argv);
}

int		ft_check_map(char *argv)
{
	int		fd;
	int		i;
	char	buf;
	char	str[BUF_SIZE];

	i = 0;
	fd = open(argv, O_RDWR);
	if (fd == -1)
		return (1);
	while (read(fd, &buf, 1))
	{
		if (buf != '\n')
		{
			str[i] = buf;
			i++;
		}
		else
			break ;
	}
	str[i] = '\0';
	ft_create_map(str, argv);
	if (close(fd) == -1)
		return (1);
	return (0);
}
