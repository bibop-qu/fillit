/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:50:20 by cbossard          #+#    #+#             */
/*   Updated: 2015/12/11 14:43:07 by basle-qu         ###   ########.fr       */
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

void	init_pos(t_piece *piece)
{
	int		i;
	int 	j;

	while(!strchr(piece->form[0], '#'))
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
	while (!verif_col(piece->form, 0))
	{
		i = 0;
		while (i < 4)
		{
			j = -1;
			while (++j < 3)
				piece->form[i][j] = piece->form[i][j + 1];
			piece->form[i][3] = '.';
			i++;
		}
	}
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
