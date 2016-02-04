/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:25:46 by basle-qu          #+#    #+#             */
/*   Updated: 2016/02/04 16:38:16 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

char	**ft_init_tetri(char *av);
char	**ft_clear_tetri(char **tetri);
void	init_size(t_piece *piece);
void	init_pos(t_piece *piece);

#endif
