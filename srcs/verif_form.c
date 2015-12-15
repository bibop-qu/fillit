
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
			}
			i++;
		}
		j++;
	}
	if (nbr != 4)
		return (0);
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
