/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:32:48 by cbossard          #+#    #+#             */
/*   Updated: 2015/12/10 12:32:48 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_head	*creat_head()
{
	t_head	*news;

	news = (t_head)malloc(sizeof(t_head));
	if (!news)
	{
		write(2, "ERROR: failed to alloc memorie:1\n", 33);
		return (0);
	}
	news->size_max = 0;
	news->begin = 0;
	news->lettre = 0;
	return (news);
}

void	free_head(t_head *chain)
{
	if (chain)
	{
		chain->size_max = 0;
		chain->begin = 0;
		free(chain);
	}
}
