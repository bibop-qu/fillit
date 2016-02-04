/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:32:04 by basle-qu          #+#    #+#             */
/*   Updated: 2016/02/04 17:32:19 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	s_piece t_piece;
typedef struct	s_head t_head;

# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "chain.h"
# include "piece_tools.h"
# include "tools.h"
# include "head_tools.h"
# include "verif.h"
# include "init.h"
# include "print.h"
# include "verif_form.h"
# include "solve.h"

struct			s_piece
{
	char				**form;
	int					x_pos;
	int					y_pos;
	int					x_size;
	int					y_size;
	struct s_piece		*next;
	struct s_piece		*prev;
};

struct			s_head
{
	int			size_max;
	char		lettre;
	t_piece		*begin;
 };

#endif
