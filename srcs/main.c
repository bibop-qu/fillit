/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:47:36 by basle-qu          #+#    #+#             */
/*   Updated: 2015/12/10 12:49:16 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "error.h"
#include "tools.h"
#include "init.h"

int		main(int ac, char **av)
{
	int	i;
	char **tetri;

	i = 0;
	if (ac != 2)
		ft_use();
	tetri = ft_init_tetri(av[1]);
	while (tetri[i])
	{
		ft_putendl(tetri[i]);
		i++;
	}
	ft_putendl("Hello World!");
	return (0);
}
