/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:18:30 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/22 18:21:17 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/fillit.h"

int		check_char(char c)
{
	if (c == '#' || c == '.' || c == '\n')
		return (1);
	return (0);
}

int		ft_nb_map(char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == '\n' && (str[i - 1] == '\n' || str[i + 1] == '\0'))
			nb++;
		i++;
	}
	return (nb);
}

void	ft_count_element(char *str, int i, t_map *check)
{
	if (str[i] == '#')
		check->dieses++;
	if (str[i] == '.')
		check->point++;
	if (str[i] == '\n' && str[i - 1] != '\n')
		check->lines++;
}

int		check_map(char *str)
{
	t_map	check;
	int		i;

	i = 0;
	ft_memset(&check, 0, sizeof(t_map));
	while (str[i] && check_char(str[i]))
	{
		ft_count_element(str, i, &check);
		if (str[i] == '\n' && str[i - 1] == '\n' && str[i + 1] != '\0')
		{
			if (check.point != 12 || check.dieses != 4 || check.lines != 4)
				return (0);
			ft_memset(&check, 0, sizeof(t_map));
		}
		else if (str[i] == '\n' && str[i + 1] == '\0')
		{
			if ((str[i - 1] == '\n') ^ (check.point != 12 ||
						check.dieses != 4 || check.lines != 4))
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}
