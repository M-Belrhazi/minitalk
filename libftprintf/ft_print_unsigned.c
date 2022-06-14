/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:47:59 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/21 14:48:57 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putnbr_unsigned_fd(unsigned int nb, int fd, int *nb_char)
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
		ft_putnbr_unsigned_fd(nb / 10, fd, nb_char);
		c = nb % 10 + '0';
		write(fd, &c, 1);
		(*nb_char)++;
	}
}

void	ft_print_unsigned(va_list args, int *nb_char)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	ft_putnbr_unsigned_fd(nb, 1, nb_char);
}
