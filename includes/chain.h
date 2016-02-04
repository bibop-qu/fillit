/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:56:53 by cbossard          #+#    #+#             */
/*   Updated: 2015/12/11 14:45:40 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAIN_H
# define CHAIN_H

# include "fillit.h"

t_head	*creat_chain(char **tetri);
t_head	*cp_chain(t_head *chain);
void	free_chain(t_head *chain);
int		chain_len(t_head *chain);

#endif
