/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:58:57 by basle-qu          #+#    #+#             */
/*   Updated: 2016/02/04 15:29:33 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**cp_tab(char **tab)
{
	char	**news;
	int		size;
	int		i;

	size = ft_strlen(tab[0]);
	news = (char**)malloc(sizeof(char*) * size + 1);
	if (!news)
		ft_error("ERROR: fail alloc memorie\n");
	news[size] = 0;
	i = -1;
	while (++i < size)
	{
		news[i] = (char*)malloc(sizeof(char) * size + 1);
		if (!news[i])
			ft_error("ERROR: fail alloc memorie\n");
		ft_strcpy(news[i], tab[i]);
	}
	return (news);
}

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(0);
}

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
