/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:18:34 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/23 15:21:54 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/fillit.h"

int				ft_call_fct(char *map)
{
	t_last	list;
	t_last	dup;
	t_last	mat;
	t_list	*elem;

	ft_init_lst_dbl(&list);
	ft_init_lst_dbl(&dup);
	ft_init_lst_dbl(&mat);
	ft_seperate_tetris(map, &list);
	if (list.taille > 26)
	{
		ft_putendl("error");
		return (0);
	}
	ft_create_mat(&mat);
	if (ft_check_form(&list, &mat) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	elem = list.fin;
	ft_solver_tetri(&list, &dup, map, elem);
	return (1);
}

static char		*ft_read_file(char *file)
{
	int		fd;
	int		ret;
	char	*map;
	char	buf[BUFF_SIZE + 1];

	map = "";
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (ret > 0)
			map = ft_strdup(buf);
		else if (ret == -1)
			return (NULL);
	}
	if (close(fd) == -1)
		return (NULL);
	else if (close(fd) == 0)
		ft_putstr("end_file");
	return (map);
}

int				ft_file_reader(char *file)
{
	char	*map;

	map = ft_read_file(file);
	if (map == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (check_map(map) == 0 || map == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_call_fct(map);
	return (0);
}
