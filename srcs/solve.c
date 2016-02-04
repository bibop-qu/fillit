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

int		init_size_max(int n_piece)
{
	int i;

	i = 0;
	while (i * i <= 4 * n_piece)
		i++;
	return (i - 1);
}

int 	verif_col(char **tab, int i)
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

int		verif_tab(char **tab, t_piece *p)
{
	//ft_putendl("VERIF_TAB");
	int		i;
	int		j;

	i = -1;
	while (++i < p->y_size)
	{
		j = -1;
		while (++j < p->x_size)
			if (p->form[i][j] == '#' && tab[i + p->y_pos][j + p->x_pos] == '#')
			{
				//ft_putendl("END_VERIF_TAB_1");
				return (0);
			}
	}
	//ft_putendl("END_VERIF_TAB_2");
	return (1);
}

int	to_do_the_coffe(t_head *c, t_piece *p, char **tab)
{
	//ft_putendl("COFEE");
	char	**not_the_same_tab;

	p->y_pos = -1;
	while (++p->y_pos <= c->size_max - p->y_size)
	{
		p->x_pos = -1;
		while (++p->x_pos <= c->size_max - p->x_size)
		{
			if (verif_tab(tab, p))
			{
				if (!p->next)
				{
					//ft_putendl("END_COFEE_1");
					return (42);
				}
				not_the_same_tab = cp_tab(tab);
				add_piece_in_tab(not_the_same_tab, p);
				if (to_do_the_coffe(c, p->next, not_the_same_tab))
				{
					free_tab(not_the_same_tab);
					//ft_putendl("END_COFEE_2");
					return (42);
				}
				free_tab(not_the_same_tab);
			}
		}
	}
	p->y_pos = 0;
	p->x_pos = 0;
	//ft_putendl("END_COFEE_3");
	return (0);
}

t_head	*solve(t_head *chain)
{
	t_head	*ref;
	char	**maggle;
	int		i;

	if (!chain || !chain->begin)
		return (0);
	i = 0;
	chain->size_max = init_size_max(chain_len(chain));
	while (!i)
	{
		ft_putendl("maggle");
		maggle = creat_tab(chain->size_max);
		ref = cp_chain(chain);
		i = to_do_the_coffe(chain, ref->begin, maggle);
		free_tab(maggle);
		if (!i)
		{
			free_chain(ref);
			chain->size_max++;
		}
	}
	ft_putnbr(chain->size_max);
	ft_putchar('\n');
	//ft_putendl("WHILILILILLILILILI");
	return (ref);
}
