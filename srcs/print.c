/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:37:39 by cbossard          #+#    #+#             */
/*   Updated: 2015/12/11 15:46:22 by basle-qu         ###   ########.fr       */
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
		ft_error("ERROR: fail alloc memorie\n");
	i = -1;
	news[size] = 0;
	while (++i < size)
	{
		news[i] =(char*)malloc(sizeof(char) * size + 1);
		if (!news[i])
			ft_error("ERROR: fail alloc memorie\n");
		j = -1;
		while (++j < size)
			news[i][j] = '.';
		news[i][j] = 0;
	}
	return (news);
}

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
	char	**tab;
	t_piece	*tmp;

	tab = creat_tab(chain->size_max);
	tmp = chain->begin;
	while (tmp)
	{
		i = -1;
		while (++i < 4 && i + tmp->x_pos < chain->size_max)
		{
			j = -1;
			while (++j < 4 && j + tmp->y_pos < chain->size_max)
				if (tmp->form[i][j] != '.')
					tab[i + tmp->x_pos][j + tmp->y_pos] = chain->lettre + 48;
		}
		tmp = tmp->next;
		chain->lettre += 1;
	}
}

void	debugg_print_maggle_just_form(t_head *chain)
{
	t_piece *tmp;

	tmp = chain->begin;
	while(tmp)
	{
		write(1, "Y: ", 3);
		ft_putnbr(tmp->y_pos);
		write(1, " X: ", 4);
		ft_putnbr(tmp->x_pos);
		write(1, "\n", 1);
		print_tab(tmp->form);
		tmp = tmp->next;
		write(1, "\n", 1);
	}
}
