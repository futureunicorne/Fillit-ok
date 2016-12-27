/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:44:23 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/22 19:01:27 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 600

# include "libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct		s_map
{
	int				point;
	int				dieses;
	int				lines;
}					t_map;

typedef	struct		s_pos
{
	int				x;
	int				y;
	int				place;
}					t_pos;

typedef	struct		s_var
{
	int				i;
	int				j;
	int				diff;
	int				dieses;
	t_list			*elem;
	t_list			*mat;
}					t_var;

typedef	struct		s_car
{
	char			*dst;
	int				i;
	int				j;
	int				k;
	int				flag;
	int				diff;
	int				auth;
}					t_car;

int					ft_call_fct(char *map);
int					ft_file_reader(char *file);
int					check_char(char c);
int					ft_nb_map(char *str);
int					check_map(char *str);
int					ft_add_elm_bis(t_last *list, void *content,
					size_t content_size);
int					ft_check_form(t_last *list, t_last *matrice);
int					check_count(char *str);
int					ft_place_i(char *str, int *tab);
int					ft_check_place_i(char *str, int *tab, int i);
int					check_place(char *str, int *tab);
char				*ft_place_tetri(char *str, int *tab, int i, int letter);
char				*ft_solver_tetri(t_last *list, t_last *dup, char *str,
					t_list *elem);
char				*ft_map(char *str, int k);
void				ft_init_lst_dbl(t_last *list);
void				ft_create_mat(t_last *dup);
void				call_compare_pos(char *str, t_car *car, t_pos *pos);
t_last				*ft_seperate_tetris(char *str, t_last *dup);
t_last				*ft_duplicate_list(t_last *list, t_last *dup);
#endif
