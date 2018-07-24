/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/23 16:53:41 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/24 13:35:47 by naplouvi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# define BUF_SIZE 	4096

typedef struct		s_list
{
	struct s_list	*next;
	char			data;
}					t_list;

typedef struct		s_map
{
	int				width;
	int				height;
	char			empty;
	char			obs;
	char			sqr;
	char			**tab;
}					t_map;

void				ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_strlen(char *str);
int					ft_atoi(char *str);
void				ft_putnbr(int nb);
void				print_error(void);
void				ft_create_map(char *str, char *argv);
int					ft_check_error(t_map *map, char *argv);
int					ft_check_map(char *argv);
void				ft_check_height(t_map *map, char *argv);
void				ft_check_width(t_map *map, char *argv);
void				ft_do_map(t_map *map, char *argv, int x);
void				ft_display_map(char **tab);
int					ft_char_to_tab(char **tab, char buf, int *i, int *j);

#endif
