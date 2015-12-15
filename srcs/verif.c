/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:40:25 by basle-qu          #+#    #+#             */
/*   Updated: 2015/12/14 17:22:09 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		diese_bis(char **form, int j, int i)
{
	int nbr;

	nbr = 0;
	if (j - 1 < 0 || form[j - 1][i] == '.')
		nbr++;
	if (i + 1 > 3 || form[j][i + 1] == '.')
		nbr++;
	if (i - 1 < 0 || form[j][i - 1] == '.')
		nbr++;
	if (j + 1 > 3 || form[j + 1][i] == '.')
		nbr++;
	return (nbr);
}

int		diese(char **form, int j, int i)
{
	int nbr;
	int	save;

	nbr = 0;
	save = 0;
	if (j - 1 < 0 || form[j - 1][i] == '.')
		nbr++;
	if (j - 1 >= 0 && save == 0 && form[j - 1][i] == '#')
		save = diese_bis(form, j - 1, i);
	if (i + 1 > 3 || form[j][i + 1] == '.')
		nbr++;
	if (i + 1 <= 3 && save == 0 && form[j][i + 1] == '#')
		save = diese_bis(form, j, i + 1);
	if (i - 1 < 0 || form[j][i - 1] == '.')
		nbr++;
	if (i - 1 >= 0 && save == 0 && form[j][i - 1] == '#')
		save = diese_bis(form, j, i - 1);
	if (j + 1 > 3 || form[j + 1][i] == '.')
		nbr++;
	if (j + 1 <= 3 && save == 0 && form[j + 1][i] == '#')
		save = diese_bis(form, j + 1, i);
	if (nbr == 3 && save == 3)
		return (4);
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
			if (form[j][i] == '#')
			{
				if ((diese(form, j, i) == 4))
					return (0);
				nbr++;
				if (nbr != 4)
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
	while (tmp->form && tmp->next)
	{
		if (verif_form(tmp->form) == 0)
			return (0);
		tmp = tmp->next;
	}
	free(tmp);
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
