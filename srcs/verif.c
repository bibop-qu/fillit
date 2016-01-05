/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:40:25 by basle-qu          #+#    #+#             */
/*   Updated: 2015/12/14 17:22:09 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		verif_line(char *line)
{
	int		i;

	i = 0;
	if (ft_strlen(line) != 4)
		return (0);
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

int		verif_block(char **tetri, int i)
{
	int		size;

	size = 0;
	while (tetri[i] && size < 4)
	{
		if (verif_line(tetri[i]) == 0)
			return (0);
		size++;
		i++;
	}
	if (size == 4)
		return (1);
	return (0);
}

int		ft_verif_tetri(char **tetri)
{
	int		i;

	i = 0;
	while (tetri[i])
	{
		if (i == 0 && !ft_strcmp(tetri[i], "\0"))
			return (0);
		if (!ft_strcmp(tetri[i], "\0"))
			i++;
		else if (i != 0)
			return (0);
		if (verif_block(tetri, i) == 0)
			return (0);
		i += 4;
	}
	return (1);
}
