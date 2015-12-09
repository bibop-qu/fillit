/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:32:04 by basle-qu          #+#    #+#             */
/*   Updated: 2015/12/09 18:01:14 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_piece
{
	char			form[4][4];
	int				x_pos;
	int				y_pos;
	struct s_piece *next;
	
}					t_piece;

#ENDIF
