/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:57:28 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/21 14:57:44 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_printf_fd(int n, int fd, int *nb_char)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		*nb_char += 11;
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
		(*nb_char)++;
	}
	ft_write_nbr(n, fd, nb_char);
}
