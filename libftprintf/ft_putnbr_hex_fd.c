/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:39:45 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/21 23:37:41 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_hex_fd(unsigned long nb, int fd, char *tab, int *nb_char)
{
	char	c;

	if (nb / 16 == 0)
	{
		c = tab[nb];
		(*nb_char)++;
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_hex_fd(nb / 16, fd, tab, nb_char);
		c = tab[nb % 16];
		(*nb_char)++;
		write(fd, &c, 1);
	}
}
