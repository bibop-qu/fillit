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

int penis(char c)
{
	write(1, &c, 1);
	return (1);
}

int verif_col(char **tab, int i)
{
	int j;

	j = 0;
	while (tab[j])
	{
		if (tab[j][i] == '#')
			return (1);
		j++;
	}
	return (0);
}

int	complete_tab(char **tab, t_piece *p)
{
//	ft_putendl("COMPLETE_TAB");
	int	i;
	int	j;
	int	size;

	size = ft_strlen(tab[0]);
	if (p->y_pos + p->y_size >= size || p->x_pos + p->x_size >= size)
		return (0);
//	print_tab(tab);
	i = 0;
	while (i < 4)
	{
		j = 0;
		if (ft_strchr(p->form[i], '#'))
			while (j < 4)
			{
				if (verif_col(p->form, j))
				{
/*					ft_putchar('\n');
					ft_putstr("y_pos: ");
					ft_putnbr(p->y_pos);
					ft_putchar('\n');
					ft_putstr("x_pos: ");
					ft_putnbr(p->x_pos);
					ft_putchar('\n');
					ft_putstr("i: ");
					ft_putnbr(i);
					ft_putchar('\n');
					ft_putstr("j: ");
					ft_putnbr(j);
					ft_putchar('\n');
					ft_putstr("size: ");
					ft_putnbr(size);
					ft_putchar('\n');*/
					if (p->form[i][j] == '#' && (tab[p->y_pos + i][p->x_pos + j] == '#' || tab[p->y_pos + i][p->x_pos + j] == '\0'))
						return (0);
//					ft_putendl("bug2");
//					if (p->form[i][j] == '#')
					tab[p->y_pos + i][p->x_pos + j] = '#';
				}
				j++;
			}
		i++;
	}
//	ft_putendl("WHALALALALALALA");
	return (1);
}

int		verif_tab(char **tab, t_piece *first)
{
//	ft_putendl("VERIF_TAB");
	while (first)
	{
		if (!complete_tab(tab, first))
			return (0);
		first = first->prev;
	}
//	ft_putendl("WHOLOLOLOLOLOLO");
	return (1);
}

char	**result(t_head * chain, t_piece *piece)
{
//	ft_putendl("RESULT");
	char	**tab;

	tab = creat_tab(chain->size_max);
	if (!verif_tab(tab, piece))
	{
//		ft_putendl("bug3");
		free_tab(tab);
		return (0);
	}
//	ft_putendl("WHULULULULULULULU");
	return (tab);
}

char	**to_do_the_coffe(t_head *c, t_piece *p)
{
//	ft_putendl("COFEE");
	int		x_init;
	int		y_init;
	char	**tab;

	if (!p)
		return (0);
	x_init = p->x_pos;
	y_init = p->y_pos;
	while (p->y_pos + p->y_size <= c->size_max)
	{
		p->x_pos = x_init;
		while (p->x_pos + p->x_size <= c->size_max)
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
		p->y_pos++;
	}
	p->y_pos = y_init;
	p->x_pos = x_init;
	return (0);
}

t_head	*solve(t_head *chain)
{
	t_head	*ref;
	char	**maggle;

	if (!chain || !chain->begin)
		return (0);
	maggle = 0;
	chain->size_max = 0;
	while (!maggle)
	{
//		ft_putendl("maggle");
		chain->size_max++;
		ref = cp_chain(chain);
		maggle = to_do_the_coffe(chain, ref->begin);
		if (!maggle)
			free_chain(ref);
	}
//	ft_putendl("WHILILILILLILILILI");
	free_tab(maggle);
//	ft_putendl("WHYLYLYLYLYLYLYLYLY");
	return (ref);
}
