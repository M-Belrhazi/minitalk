/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:38:18 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/21 14:39:56 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_hex(va_list args, char c, int *nb_char)
{
	unsigned int	x;

	x = va_arg(args, unsigned int);
	if (c == 'x')
		ft_putnbr_hex_fd(x, 1, "0123456789abcdef", nb_char);
	else
		ft_putnbr_hex_fd(x, 1, "0123456789ABCDEF", nb_char);
}
