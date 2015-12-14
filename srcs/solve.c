/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 14:28:43 by cbossard          #+#    #+#             */
/*   Updated: 2015/12/14 14:28:43 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		verif_tab(char **tab, t_piece *first)
{
	while (first)
	{
		
	}
}

char	**result(t_piece *piece)
{
	char	**tab;
	int		size_max;

	size_max = 0;
	while (piece->prev)
	{
		if (piece->x_pos + piece->x_size > size_max)
			size_max = piece->x_pos + piece->x_size;
		if (piece->y_pos + piece->y_size > size_max)
			size_max = piece->y_pos + piece->y_size;
		piece = piece->prev;
	}
	tab = creat_tab(size_max);

}

char	**to_do_the_coffe(t_piece *piece)
{
	int		x_init;
	int		y_init;

	if (!piece)
		return (0);
	x_init = piece->x_pos;
	y_init = piece->y_pos;
	while (!to_do_the_coffe(piece->next))
	{

	}
}

t_head	*solve(t_head *chain)
{
	t_head	*ref;
	t_piece	*tmp;

	if (!chain || !chain->begin)
		return (0);
	chain->size_max = 2 + 2 * chain_len(chain);
	ref = cp_chain(chain);
}
