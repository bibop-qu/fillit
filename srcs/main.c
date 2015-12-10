/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:47:36 by basle-qu          #+#    #+#             */
/*   Updated: 2015/12/10 17:44:25 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "tools.h"
#include "init.h"
#include "verif.h"

int		main(int ac, char **av)
{
	int	i;
	char **tetri;

	i = 0;
	if (ac != 2)
		ft_error("Usage: ./fillit ARG\nWhere ARG is a valid file\n");
	tetri = ft_init_tetri(av[1]);
	if (ft_verif_tetri(tetri) == 0)
		ft_error("Not a valid file!!\n");
	ft_putendl("lol");
	while (tetri[i])
	{
		ft_putendl(tetri[i]);
		i++;
	}
	ft_putendl("Hello World!");
	return (0);
}
