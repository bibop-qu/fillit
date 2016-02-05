
#ifndef STRUCT_H
# define STRUCT_H

typedef struct			s_piece
{
	char				**form;
	int					x_pos;
	int					y_pos;
	int					x_size;
	int					y_size;
	struct s_piece		*next;
	struct s_piece		*prev;
}						t_piece;

typedef struct			s_head
{
	int			size_max;
	char		lettre;
	t_piece		*begin;
 }						t_head;

#endif
