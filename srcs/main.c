/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:47:36 by basle-qu          #+#    #+#             */
/*   Updated: 2015/12/14 14:16:37 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_head	*read_file(char *av)
{
	t_head *chain;
	char **tetri;

	chain = NULL;
	tetri = ft_init_tetri(av);
	if (ft_verif_tetri(tetri) == 0)
		ft_error("Not a valid file!!\n");
	chain = creat_chain(tetri);
/*	if (ft_verif_form(chain) == 0)
	ft_error("Form not valid!!\n");*/
	free_tab(tetri);
	return (chain);
}

int		main(int ac, char **av)
{
	t_head	*chain;

	chain = NULL;
	if (ac != 2)
		ft_error("Usage: ./fillit ARG\nWhere ARG is a valid file\n");
	chain = read_file(av[1]);
	debugg_print_maggle_just_form(chain);
	ft_putendl("Hello World!");
	return (0);
}
