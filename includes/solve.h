/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:39:36 by cbossard          #+#    #+#             */
/*   Updated: 2016/02/04 16:11:16 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

t_head	*solve(t_head *chain);
int		to_do_the_coffe(t_head *c, t_piece *p, char **tab);
int		verif_col(char **tab, int i);

#endif
