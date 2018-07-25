/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 19:14:47 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 19:14:49 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/header.h"

int		main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		print_error();
	while (argv[i])
	{
		if (ft_check_map(argv[i]) == 1)
			print_error();
		if (i < argc - 1)
			ft_putchar('\n');
		i++;
	}
	return (0);
}
