/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:18:37 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/27 09:21:20 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/fillit.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_file_reader(argv[1]);
	if (argc != 2)
		ft_putendl("Usage: ./fillit [map.fillit]");
	return (0);
}
