/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:50:20 by cbossard          #+#    #+#             */
/*   Updated: 2016/02/04 16:35:18 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	add_piece_in_tab(char **tab, t_piece *piece)
{
	int		i;
	int		j;

	i = -1;
	while (++i < piece->y_size)
	{
		j = -1;
		while (++j < piece->x_size)
			if (piece->form[i][j] == '#')
				tab[i + piece->y_pos][j + piece->x_pos] = '#';
	}
}

void	cp_pos(t_piece *piece, int x, int y)
{
	piece->x_pos = x;
	piece->y_pos = y;
}

void	creat_form(t_piece *news, char **form)
{
	int i;
	int	j;

	j = 0;
	news->form = (char**)malloc(sizeof(char*) * 4 + 1);
	if (!news->form)
		ft_error("ERROR: fail malloc\n");
	news->form[4] = NULL;
	while (j < 4)
	{
		i = 0;
		news->form[j] = (char*)malloc(sizeof(char) * 4 + 1);
		if (!news->form[j])
			ft_error("ERROR: fail malloc\n");
		news->form[j][4] = 0;
		while (i < 4)
		{
			news->form[j][i] = form[j][i];
			i++;
		}
		j++;
	}
}

t_piece	*creat_piece(t_piece *prev, char **form)
{
	t_piece	*news;

	news = (t_piece*)malloc(sizeof(t_piece));
	if (!news)
		ft_error("ERROR: failed to alloc memorie\n");
	news->prev = prev;
	news->next = 0;
	creat_form(news, form);
	news->x_pos = 0;
	news->y_pos = 0;
	news->x_pos = 0;
	news->y_pos = 0;
	init_pos(news);
	init_size(news);
	return (news);
}

void	free_piece(t_piece *piece)
{
	if (piece)
	{
		piece->next = 0;
		piece->prev = 0;
		free_tab(piece->form);
		free(piece);
	}
}
