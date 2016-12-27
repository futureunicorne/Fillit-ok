/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:18:43 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/22 17:07:49 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/fillit.h"

t_last		*ft_duplicate_list(t_last *list, t_last *dup)
{
	t_list *elem;

	ft_init_lst_dbl(dup);
	elem = list->fin;
	while (elem != NULL)
	{
		ft_add_elm_bis(dup, elem->content, 8);
		elem = elem->prev;
	}
	return (dup);
}

static int	ft_resolv(t_last *list, t_list *elem, char *str)
{
	int		i;
	char	*dst;

	i = 0;
	while (i < (int)ft_strlen(str))
	{
		dst = ft_strdup(str);
		if (ft_check_place_i(dst, elem->content, i) == 1)
		{
			dst = ft_place_tetri(dst, elem->content, i, elem->content[8]);
			if (elem->prev == NULL)
			{
				ft_putstr(dst);
				ft_putchar('\n');
				return (1);
			}
			if (ft_resolv(list, elem->prev, dst) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int			ft_init_resolv(t_last *list, t_last *dup, char *str, int diff)
{
	char	*dst;
	t_list	*elem;

	ft_init_lst_dbl(dup);
	ft_duplicate_list(list, dup);
	dst = ft_map(str, diff);
	elem = list->fin;
	if (ft_resolv(dup, elem, dst) == 0)
		return (0);
	return (1);
}

char		*ft_solver_tetri(t_last *list, t_last *dup, char *str, t_list *elem)
{
	t_car	car;

	ft_memset(&car, 0, sizeof(t_car));
	car.dst = ft_map(str, car.diff);
	while (elem != NULL)
	{
		if (check_place(car.dst, elem->content) == 1)
			car.dst = ft_place_tetri(car.dst, elem->content,
			ft_place_i(car.dst, elem->content), elem->content[8]);
		else if (check_place(car.dst, elem->content) == 0)
		{
			if (ft_init_resolv(list, dup, str, car.diff) == 1)
				return (NULL);
			car.flag = 1;
		}
		elem = elem->prev;
		if (car.flag == 1)
		{
			car.flag = 0;
			elem = dup->fin;
			car.dst = ft_map(str, car.diff++);
		}
	}
	ft_putendl(car.dst);
	return (car.dst);
}
