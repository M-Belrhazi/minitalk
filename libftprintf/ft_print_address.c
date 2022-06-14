/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:36:29 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/21 23:38:06 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_address(va_list args, int *nb_char)
{
	unsigned long	ptr;

	ptr = va_arg(args, unsigned long);
	if (ptr == 0)
	{
		ft_putstr_printf_fd("(nil)", 1, nb_char);
		return ;
	}
	write(1, "0x", 2);
	*nb_char += 2;
	ft_putnbr_hex_fd(ptr, 1, "0123456789abcdef", nb_char);
}
