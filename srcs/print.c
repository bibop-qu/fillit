/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:37:39 by cbossard          #+#    #+#             */
/*   Updated: 2015/12/10 15:37:40 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**creat_tab(int size)
{
	char	**news;
	int		i;
	int		j;

	news = (char**)malloc(sizeof(char*) * size + 1);
	if (!news)
		return (0);
	i = -1;
	news[size] = 0;
	while (++i < size)
	{
		news[i] =(char*)malloc(sizeof(char) * size + 1);
		if (!news[i])
		{
			write(2, "ERROR: failed to alloc memorie\n", 32);
			return (0);
		}
		j = -1;
		while (++j < size)
			news[i][j] = '.';
		news[i][j] = 0;
	}
	return (news);
}

void	print(t_head *chain)
{
	int		i;
	int		j;
	char	**tab;
	t_piece	*tmp;

	if (tab = creat_tab(chain->max_size))
		return (0);
	tmp = chain->begin;
	while (tmp)
	{
		i = -1;
		while (++i < 4 && i + tmp->x_pos < chain->max_size)
		{
			j = -1;
			while (++j < 4 && j + tmp->y_pos < chain->max_size)
				if (tmp->form[i][j] != '.')
					tab[i + x_pos][j + y_pos] = chain->lettre + 48;
		}
		tmp = tmp->next;
		chain->lettre += 1;
	}
}
