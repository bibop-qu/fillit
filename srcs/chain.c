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
	actu = chain->begin;
	news->begin = creat_piece(0, actu->form);
	tmp = news->begin;
	while (actu)
	{
		prev = tmp;
		tmp = creat_piece(prev, actu->form);
		prev->next = tmp;
		actu = actu->next;
		tmp = tmp->next;
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
