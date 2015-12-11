/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:32:04 by basle-qu          #+#    #+#             */
/*   Updated: 2015/12/11 14:51:12 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_piece
{
	char			**form;
	int				x_pos;
	int				y_pos;
	struct s_piece *next;
	struct s_piece *prev;
}					t_piece;

typedef struct		s_head
{
	unsigned int	size_max;
	char			lettre;
	t_piece			*begin;
}					t_head;

# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "chain.h"
# include "piece_tools.h"
# include "tools.h"
# include "head_tools.h"
# include "verif.h"
# include "init.h"

#endif
