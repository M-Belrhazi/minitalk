/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:59:26 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/21 14:59:42 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_write_nbr(int nb, int fd, int *nb_char)
{
	char	c;

	if (nb / 10 == 0)
	{
		c = nb + '0';
		write(fd, &c, 1);
		(*nb_char)++;
	}
	else
	{
		ft_write_nbr(nb / 10, fd, nb_char);
		c = nb % 10 + '0';
		write(fd, &c, 1);
		(*nb_char)++;
	}
}
