/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_standard_create.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 20:10:24 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 20:53:44 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/header.h"

int		ft_standard_char_to_tab(char **tab, char buf, int *i, int *j)
{
	if (buf == '\n')
	{
		tab[*i][*j] = buf;
		tab[*i][*j + 1] = '\0';
		*j = 0;
		(*i)++;
		return (0);
	}
	else
	{
		tab[*i][*j] = buf;
		(*j)++;
	}
	return (1);
}

void	ft_do_standard_map(t_map *map, char *argv, int x)
{
	int		i;
	int		j;
	int		k;

	map->width = x;
	i = 0;
	j = 0;
	k = -1;
	map->tab = NULL;
	if ((map->tab = malloc(sizeof(char *) * (map->height + 2))) == NULL)
		return ;
	while (i < (map->height + 1))
	{
		if ((map->tab[i] = malloc(sizeof(char) * (map->width + 1))) == NULL)
			return ;
		while (argv[++k])
		{

			if (ft_standard_char_to_tab(map->tab, argv[k], &i, &j) == 0)
				break ;
		}
	}
	map->tab[i] = NULL;
	ft_resolve_map(map);
}
