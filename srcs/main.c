/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/23 16:59:26 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/24 16:46:29 by ftourret    ###    #+. /#+    ###.fr     */
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
		i++;
	}
	return (0);
}
