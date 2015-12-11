/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:58:57 by basle-qu          #+#    #+#             */
/*   Updated: 2015/12/11 14:49:08 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(0);
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}	

char    **ft_realloc(char **tab, char *line)
{
    int     i;
    char    **result;

    i = 0;
    if (tab == NULL)
    {
        result = (char**)malloc(sizeof(char*) * 2);
        result[i] = ft_strdup(line);
        result[i + 1] = NULL;
    }
    else
    {
        while (tab[i])
            i++;
        result = (char**)malloc(sizeof(char*) * (i + 2));
        i = -1;
        while (tab[++i])
            result[i] = ft_strdup(tab[i]);
        result[i] = ft_strdup(line);
        result[i + 1] = NULL;
    }
	if (tab)
		free_tab(tab);
    return (result);
}
