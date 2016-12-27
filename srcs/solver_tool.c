/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 14:32:03 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/22 17:07:48 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/fillit.h"

static void	call_place_i(char *str, int *tab, t_car *car, t_pos *pos)
{
	if (str[car->j] == '\n')
	{
		car->diff = check_count(str) - pos->y;
		pos->x--;
		pos->y = -1 - car->diff;
	}
	if (pos->x == tab[car->k] && pos->y == tab[car->k + 1])
	{
		if (str[car->j] == '.')
			car->auth++;
		car->k = car->k + 2;
	}
}

int			ft_check_place_i(char *str, int *tab, int i)
{
	t_pos pos;
	t_car car;

	ft_memset(&pos, 0, sizeof(t_pos));
	ft_memset(&car, 0, sizeof(t_car));
	if (str[i] == '.')
	{
		car.auth = 0;
		ft_memset(&pos, 0, sizeof(t_pos));
		car.j = i;
		car.k = 0;
		while (str[car.j] ^ (car.k == 7))
		{
			call_place_i(str, tab, &car, &pos);
			if (car.auth == 4)
				return (1);
			car.j++;
			pos.y++;
		}
	}
	return (0);
}

char		*ft_place_tetri(char *str, int *tab, int i, int letter)
{
	char	*dst;
	t_pos	pos;
	t_car	car;

	dst = ft_strdup(str);
	ft_memset(&pos, 0, sizeof(t_pos));
	ft_memset(&car, 0, sizeof(t_car));
	car.j = i;
	while (car.auth != 4)
	{
		call_compare_pos(str, &car, &pos);
		if (pos.x == tab[car.k] && pos.y == tab[car.k + 1])
		{
			dst[car.j] = 'A' + letter;
			car.auth++;
			car.k = car.k + 2;
		}
		car.j++;
		pos.y++;
	}
	return (dst);
}

int			ft_place_i(char *str, int *tab)
{
	t_car	car;
	t_pos	pos;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			ft_memset(&pos, 0, sizeof(t_pos));
			ft_memset(&car, 0, sizeof(t_car));
			car.j = i;
			while (str[car.j] ^ (car.k == 7))
			{
				call_place_i(str, tab, &car, &pos);
				if (car.auth == 4)
					return (i);
				car.j++;
				pos.y++;
			}
		}
		car.diff++;
		i++;
	}
	return (2);
}

int			check_place(char *str, int *tab)
{
	t_car	car;
	t_pos	pos;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			ft_memset(&pos, 0, sizeof(t_pos));
			ft_memset(&car, 0, sizeof(t_car));
			car.j = i;
			while (str[car.j] ^ (car.k == 7))
			{
				call_place_i(str, tab, &car, &pos);
				if (car.auth == 4)
					return (1);
				car.j++;
				pos.y++;
			}
		}
		car.diff++;
		i++;
	}
	return (0);
}
