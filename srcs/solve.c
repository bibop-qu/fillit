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

int	complete_tab(char **tab, t_piece *p)
{
	int	i;
	int	j;
	int	size;

	size = ft_strlen(tab[0]);
	if (p->y_pos + p->y_size > size || p->x_pos + p->x_size > size)
		return (0);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (p->form[i][j] == '#' && tab[p->y_pos + i][p->x_pos + j] == '#')
				return (0);
			if (p->form[i][j] == '#')
				tab[p->y_pos + i][p->x_pos + j] = '#';
			j++;
		}
		i++;
	}
	return (1);
}

int		verif_tab(char **tab, t_piece *first)
{
	while (first)
	{
		if (!complete_tab(tab, first))
			return (0);
		first = first->prev;
	}
	return (1)
}

char	**result(t_head * chain, t_piece *piece)
{
	char	**tab;
	t_piece	*tmp;

	tab = creat_tab(chain->size_max);
	if (!verif_tab(tab, tmp))
	{
		free_tab(tab);
		return (0);
	}
	return (tab);
}

char	**to_do_the_coffe(t_head *c, t_piece *p)
{
	int		x_init;
	int		y_init;
	char	**tab;

	if (!p)
		return (0);
	x_init = p->x_pos;
	y_init = p->y_pos;
	while (p->y_pos + p->y_size < c->size_max)
	{
		p->x_pos = x_init;
		while (p->x_pos + p->x_size < c->size_max)
		{
			if (p->next)
			{
				tab = to_do_the_coffe(c, p->next);
				if (tab)
					return (tab);
			}
			else
			{
				tab = result(c, p);
				if (tab)
					return (tab);
			}
			p->x_pos++;
		}
	}
	return (0);
}

t_head	*solve(t_head *chain)
{
	t_head	*ref;
	char	**maggle;

	if (!chain || !chain->begin)
		return (0);
	maggle = 0;
	while (!maggle)
	{
		chain->size_max++;
		ref = cp_chain(chain);
		maggle = to_do_the_coffe(chain, ref->next);
		if (!maggle)
			free_chain(ref);
	}
	free_tab(maggle);
	return (ref);
}
