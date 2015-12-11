/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:50:20 by cbossard          #+#    #+#             */
/*   Updated: 2015/12/10 12:50:21 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init_pos(t_piece *piece)
{
	int	i;
	int j;

	i = 3;
	piece->x_pos = -4;
	piece->y_pos = -4;
	while (i >= 0)
	{
		if (ft_strchr(piece->form[i], '#'))
			piece->y_pos = -i;
		i--;
	}
	i = 3
	while (i >= 0)
	{
		j = 0;
		while (j < 4)
		{
			if (piece->form[j][i] == '#')
				piece->x_pos = -i;
			j++;
		}
		i--;
	}
}

t_piece	*creat_piece(t_piece *prev, char **form)
{
	t_piece	*news;
	char	i;
	char	j;

	news = (t_piece)malloc(sizeof(t_piece));
	if (!news)
		ft_error("ERROR: failed to alloc memorie\n");
	j = 0;
	news->prev = prev;
	news->next = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			news->form[j][i] = form[j][i];
			i++;
		}
		j++;
	}
	return (news);
}

void	free_piece(t_piece *piece)
{
	char	i;
	char	j;

	if (piece)
	{
		piece->next = 0;
		piece->prev = 0;
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				piece->form = 0;
				j ++;
			}
			i++;
		}
		free(piece);
	}
}
