/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_tool_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 14:42:46 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/22 17:07:47 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/fillit.h"

static int		ft_sqrt_2(int nb)
{
	int i;

	i = 1;
	while (i < (nb / 2))
	{
		if (i * i >= nb)
			return (i);
		i++;
	}
	return (0);
}

int				check_count(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
	{
		i++;
	}
	return (i);
}

char			*ft_map(char *str, int k)
{
	char	*map;
	int		cal;
	int		len;
	int		i;
	int		j;

	cal = ft_nb_map(str) * 4;
	len = (ft_sqrt_2(cal) + k) * (ft_sqrt_2(cal) + k) + ft_sqrt_2(cal) + k;
	i = 0;
	j = 0;
	if ((map = (char*)malloc(sizeof(char) * (len))) == NULL)
		return (NULL);
	while (i < len - 1)
	{
		if (j == ft_sqrt_2(cal) + k)
		{
			map[i] = '\n';
			j = 0;
			i++;
		}
		map[i++] = '.';
		j++;
	}
	map[i] = '\0';
	return (map);
}

void			call_compare_pos(char *str, t_car *car, t_pos *pos)
{
	if (str[car->j] == '\n')
	{
		car->diff = check_count(str) - pos->y;
		pos->x--;
		pos->y = -1 - car->diff;
	}
}
