/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_tools.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:13:21 by cbossard          #+#    #+#             */
/*   Updated: 2015/12/10 14:13:33 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIECE_TOOLS_H
# define PIECE_TOOLS_H

t_piece	*creat_piece(t_piece *prev, char **form, int x, int y);
void	*free_piece(t_piece *piece);

#endif
