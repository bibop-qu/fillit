/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:59:11 by basle-qu          #+#    #+#             */
/*   Updated: 2016/02/04 16:10:15 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

char	**cp_tab(char **tab);
void	free_tab(char **tab);
char	**ft_realloc(char **tab, char *line);
void	ft_error(char *str);
char	**creat_tab(int size);

#endif
