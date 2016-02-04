/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:37:39 by cbossard          #+#    #+#             */
/*   Updated: 2016/02/04 17:18:17 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}

void	print(t_head *chain)
{
	int		i;
	int		j;
	char	**tb;
	t_piece	*p;

	tb = creat_tab(chain->size_max);
	p = chain->begin;
	while (p)
	{
		i = -1;
		while (++i < 4 && i + p->y_pos < chain->size_max)
		{
			j = -1;
			if (ft_strchr(p->form[i], '#'))
				while (++j < 4 && j + p->x_pos < chain->size_max)
				{
					if (p->form[i][j] != '.')
						tb[i + p->y_pos][j + p->x_pos] = chain->lettre + 'A';
				}
		}
		p = p->next;
		chain->lettre += 1;
	}
	print_tab(tb);
}

void	debugg_print_maggle_just_form(t_head *chain)
{
	t_piece *tmp;

	tmp = chain->begin;
	while (tmp)
	{
		write(1, "Y: ", 3);
		ft_putnbr(tmp->y_pos);
		write(1, " X: ", 4);
		ft_putnbr(tmp->x_pos);
		write(1, "\n", 1);
		write(1, "y: ", 3);
		ft_putnbr(tmp->y_size);
		write(1, " x: ", 4);
		ft_putnbr(tmp->x_size);
		write(1, "\n", 1);
		print_tab(tmp->form);
		tmp = tmp->next;
		write(1, "\n", 1);
	}
}
