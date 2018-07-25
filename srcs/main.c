/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/23 16:59:26 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 17:20:13 by naplouvi    ###    #+. /#+    ###.fr     */
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
