/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:44:35 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/22 19:40:51 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/fillit.h"

void			ft_create_mat(t_last *dup)
{
	t_var		var;
	int			*tab;
	static int	matrice[19][8] = { {0, 0, 0, 1, -1, 0, -1, 1},
	{0, 0, -1, 0, -2, 0, -3, 0}, {0, 0, 0, 1, -1, 1, -1, 2},
	{0, 0, 0, 1, -1, -1, -1, 0}, {0, 0, -1, 0, -1, 1, -2, 1},
	{0, 0, -1, -1, -1, 0, -2, -1}, {0, 0, 0, 1, 0, 2, -1, 1},
	{0, 0, -1, -1, -1, 0, -1, 1}, {0, 0, -1, -1, -1, 0, -2, 0},
	{0, 0, -1, 0, -1, 1, -2, 0}, {0, 0, -1, 0, -2, 0, -2, 1},
	{0, 0, -1, 0, -2, -1, -2, 0}, {0, 0, 0, 1, -1, 0, -2, 0},
	{0, 0, 0, 1, -1, 1, -2, 1}, {0, 0, 0, 1, 0, 2, -1, 0},
	{0, 0, -1, 0, -1, 1, -1, 2}, {0, 0, -1, -2, -1, -1, -1, 0},
	{0, 0, 0, 1, 0, 2, -1, 2}, {0, 0, 0, 1, 0, 2, 0, 3} };

	ft_memset(&var, 0, sizeof(t_var));
	while (var.i < 19)
	{
		tab = (int*)malloc(sizeof(int) * 8);
		var.j = 0;
		while (var.j < 8)
		{
			tab[var.j] = matrice[var.i][var.j];
			var.j++;
		}
		ft_add_elm_bis(dup, (int*)tab, 7);
		var.i++;
	}
}

static void		call_check_form(t_var *var)
{
	if (var->i == 7)
	{
		var->j++;
		var->mat = NULL;
	}
	else
		var->mat = var->mat->next;
}

int				ft_check_form(t_last *list, t_last *matrice)
{
	t_var var;

	ft_memset(&var, 0, sizeof(t_var));
	var.elem = list->debut;
	var.mat = matrice->debut;
	while (var.elem != NULL)
	{
		var.mat = matrice->debut;
		while (var.mat != NULL)
		{
			var.i = 0;
			while (var.elem->content[var.i] == var.mat->content[var.i]
			&& var.i < 7)
				var.i++;
			call_check_form(&var);
		}
		var.elem = var.elem->next;
	}
	if (var.j == (int)list->taille)
		return (1);
	return (0);
}
