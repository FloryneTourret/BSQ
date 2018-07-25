/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 19:14:47 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 20:41:32 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/header.h"

char	*map_standard(void)
{
	char	buf;
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	if ((str = malloc(sizeof(char *) * BUF_SIZE)) == NULL)
		return (NULL);
	while ((read(0, &buf, 1)))
	{
		str[i] = buf;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
	{
		argv[0] = map_standard();
		if (ft_check_standard_map(argv[0]) == 1)
			print_error();
	}
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
