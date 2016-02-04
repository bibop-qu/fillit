/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:25:06 by basle-qu          #+#    #+#             */
/*   Updated: 2016/02/04 17:13:24 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "tools.h"

void	baby_init_pos(t_piece *piece)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (!verif_col(piece->form, 0))
	{
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < 3)
				piece->form[i][j] = piece->form[i][j + 1];
			piece->form[i][3] = '.';
		}
	}
}

void	init_pos(t_piece *piece)
{
	int	i;

	while (!strchr(piece->form[0], '#'))
	{
		i = -1;
		free(piece->form[0]);
		while (++i < 3)
			piece->form[i] = piece->form[i + 1];
		piece->form[3] = (char*)malloc(sizeof(char) * 4 + 1);
		piece->form[3][4] = 0;
		i = -1;
		while (++i < 4)
			piece->form[3][i] = '.';
	}
	baby_init_pos(piece);
}

void	init_size(t_piece *piece)
{
	int		i;

	piece->x_size = 0;
	piece->y_size = 0;
	i = -1;
	while (++i < 4)
		if (strchr(piece->form[i], '#'))
			piece->y_size++;
	i = -1;
	while (++i < 4)
		if (verif_col(piece->form, i))
			piece->x_size++;
}

char	**ft_clear_tetri(char **tetri)
{
	int		i;
	char	**new;

	i = 0;
	new = NULL;
	while (tetri[i])
	{
		if (ft_strcmp(tetri[i], "\0"))
			new = ft_realloc(new, tetri[i]);
		i++;
	}
	free_tab(tetri);
	return (new);
}

char	**ft_init_tetri(char *av)
{
	int		fd;
	char	**tab;
	char	*line;

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
