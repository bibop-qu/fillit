/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:47:36 by basle-qu          #+#    #+#             */
/*   Updated: 2015/12/09 18:30:38 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error.h"
#include "tools.h"
#include "get_next_line.h"
#include <fcntl.h>

char	**ft_init_tetri(char *av)
{
	int fd;
	char **tab;
	char *line;

	tab = NULL;
	line = NULL;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_open_file();
	while (get_next_line(fd, &line) == 1)
	{
		tab = ft_realloc(tab, line);
		free(line);
	}
	close(fd);
	return (tab);
}

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
