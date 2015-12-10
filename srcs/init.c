/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:25:06 by basle-qu          #+#    #+#             */
/*   Updated: 2015/12/10 17:43:26 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "tools.h"

char	**ft_init_tetri(char *av)
{
	int fd;
	char **tab;
	char *line;

	tab = NULL;
	line = NULL;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error("File can't be oppen.\n");
	while (get_next_line(fd, &line) == 1)
	{
		tab = ft_realloc(tab, line);
		free(line);
	}
	close(fd);
	return (tab);
}
