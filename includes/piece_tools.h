/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_tools.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:13:21 by cbossard          #+#    #+#             */
/*   Updated: 2015/12/11 14:42:48 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIECE_TOOLS_H
# define PIECE_TOOLS_H

# include "fillit.h"

void	add_piece_in_tab(char **tab, t_piece *piece);
t_piece	*creat_piece(t_piece *prev, char **form);
void	free_piece(t_piece *piece);
void	cp_pos(t_piece *piece, int x, int y);

#endif
