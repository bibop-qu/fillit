/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:23:13 by cbossard          #+#    #+#             */
/*   Updated: 2015/12/14 13:55:31 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		chain_len(t_head *chain)
{
	int		size;
	t_piece	*tmp;

	if (!chain || chain->begin)
		return (0);
	tmp = chain->begin;
	size = 1;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

t_head	*creat_chain(char **tetri)
{
	int		i;
	t_head	*chain;
	t_piece	*tmp;

	i = 4;
	tmp = NULL;
	chain = creat_head();
	chain->begin = creat_piece(NULL, tetri);
	tmp = chain->begin;
	while (tetri[i])
	{
		tmp->next = creat_piece(tmp, tetri + i);
		tmp = tmp->next;
		i += 4;
	}
	return (chain);
}

t_head	*cp_chain(t_head *chain)
{
	t_head	*news;
	t_piece	*prev;
	t_piece	*actu;
	t_piece	*tmp;

	if (!chain)
		return (0);
	news = creat_head();
	news->size_max = chain->size_max;
	if (!chain->begin)
		return (news);
	prev = 0;
	actu = chain->begin->next;
	news->begin = creat_piece(0, chain->begin->form);
	cp_pos(news->begin, chain->begin->x_pos, chain->begin->y_pos);
	tmp = news->begin;
	while (actu)
	{
		prev = tmp;
		tmp = creat_piece(prev, actu->form);
		cp_pos(tmp, actu->x_pos, actu->y_pos);
		prev->next = tmp;
		actu = actu->next;
	}
	return (news);
}

void	free_chain(t_head *chain)
{
	t_piece	*next;
	t_piece	*tmp;

	if (chain)
	{
		next = chain->begin;
		while (next)
		{
			tmp = next;
			next = next->next;
			free_piece(tmp);
		}
		free_head(chain);
	}
}
