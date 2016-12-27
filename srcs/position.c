/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:38:25 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/22 19:57:21 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/fillit.h"

int				ft_add_elm_bis(t_last *list, void *content, size_t content_size)
{
	t_list *elem;

	if ((elem = malloc(sizeof(*elem))) == NULL)
		return (-1);
	if ((elem->content = malloc(content_size)) == NULL)
		return (-1);
	elem->content_size = content_size;
	elem->content = content;
	elem->next = list->debut;
	elem->prev = NULL;
	if (list->debut)
		list->debut->prev = elem;
	else
		list->fin = elem;
	list->debut = elem;
	list->taille++;
	return (0);
}

void			ft_init_lst_dbl(t_last *list)
{
	list->debut = NULL;
	list->fin = NULL;
	list->taille = 0;
}

static void		ft_call_count(char *str, t_var *var, t_pos *pos)
{
	if (str[var->i] == '\n' && var->dieses == 1)
		pos->x--;
	if (str[var->i] == '\n' && var->dieses == 0)
		pos->y = -1;
	if (str[var->i] == '\n' && var->dieses == 1)
		pos->y = -1 - var->diff;
	if (str[var->i] == '#' && var->dieses == 0)
	{
		var->dieses = 1;
		var->diff = pos->y;
		pos->x = 0;
		pos->y = 0;
	}
}

static int		*ft_relative_pos(char *str, int letter)
{
	int		*tab;
	t_pos	pos;
	t_var	var;

	tab = (int*)malloc(sizeof(tab) * 8);
	ft_memset(&pos, 0, sizeof(t_pos));
	ft_memset(&var, 0, sizeof(t_var));
	while (str[var.i])
	{
		ft_call_count(str, &var, &pos);
		if (str[var.i] == '#')
		{
			tab[var.j] = pos.x;
			tab[var.j + 1] = pos.y;
			var.j = var.j + 2;
		}
		pos.y++;
		var.i++;
	}
	tab[8] = letter;
	return (tab);
}

t_last			*ft_seperate_tetris(char *str, t_last *dup)
{
	char			*tetris;
	int				*tab;
	int				i;
	int				j;
	int				letter;

	i = 0;
	j = 0;
	letter = 0;
	tab = (int*)malloc(sizeof(int) * 8);
	while (str[i])
	{
		if (str[i] == '\n' && (str[i - 1] == '\n' || str[i + 1] == '\0'))
		{
			tetris = ft_strnew(i - j + 1);
			tetris = ft_strsub(str, j, i - j + 1);
			tab = ft_relative_pos(tetris, letter);
			ft_add_elm_bis(dup, (int*)tab, 8);
			j = i + 1;
			letter++;
		}
		i++;
	}
	return (dup);
}
