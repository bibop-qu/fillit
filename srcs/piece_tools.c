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

t_piece	*creat_piece(t_piece *prev, char **form, int x, int y)
{
	t_piece	*news;
	char	i;
	char	j;

	news = (t_piece)malloc(sizeof(t_piece));
	if (!news)
	{
		write(2, "ERROR: failed to alloc memorie:3\n", 33);
		return (0);
	}
	j = 0;
	news->prev = prev;
	news->next = 0;
	news->x_pos = x;
	news->y_pos = y;
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

void	*free_piece(t_piece *piece)
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
