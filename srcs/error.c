/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:07:11 by basle-qu          #+#    #+#             */
/*   Updated: 2015/12/09 17:19:27 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_use()
{
	write(2, "Usage: ./fillit ARG\nWhere ARG is a valid file\n", 46);
	exit(0);
}

void	ft_open_file()
{
	write(2, "File can't be oppen.\n", 22);
	exit(0);
}
