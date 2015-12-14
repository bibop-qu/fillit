/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:40:25 by basle-qu          #+#    #+#             */
/*   Updated: 2015/12/14 14:16:22 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		diese(char **form, int j, int i)
{
	int	nbr;

	nbr = 0;
	if (!form[j - 1][i] || form[j - 1][i] == '.')
		nbr++;
	if (!form[j][i + 1] || form[j][i + 1] == '.')
		nbr++;
	if (!form[j][i - 1] || form[j][i - 1] == '.')
		nbr++;
	if (!form[j + 1][i] || form[j + 1][i] == '.')
		nbr++;
	return (nbr);
}

int		verif_form(char **form)
{
	int		i;
	int		j;
	int		nbr;

	j = 0;
	nbr = 0;
	while (form[j])
	{
		i = 0;
		while (form[j][i])
		{
			if (form[i][j] == '#')
			{
				
				if (diese(form, j, i) == 4)
					return (0);
				nbr++;
				if (nbr > 3)
					return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int		ft_verif_form(t_head *chain)
{
	t_piece *tmp;

	tmp = chain->begin;
	while (tmp->form)
	{
		if (verif_form(tmp->form) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		verif_line(char *line)
{
	int		i;

	i = 0;
	if (ft_strlen(line) != 4)
		return (0);
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

int		verif_block(char **tetri, int i)
{
	int		size;

	size = 0;
	while (tetri[i] && size < 4)
	{
		if (verif_line(tetri[i]) == 0)
			return (0);
		size++;
		i++;
	}
	if (size == 4)
		return (1);
	return (0);
}

int		ft_verif_tetri(char **tetri)
{
	int		i;

	i = 0;
	while (tetri[i])
	{
		if (tetri[i] && verif_block(tetri, i) == 0)
			return (0);
		i += 4;
	}
		return (1);
}
