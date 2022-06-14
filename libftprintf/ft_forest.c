/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:18:11 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/21 16:49:26 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_forest(char c, va_list args, int *nb_char)
{
	if (c == 'c')
	{
		ft_print_char(args);
		(*nb_char)++;
	}
	else if (c == '%')
	{
		ft_putchar_fd(c, 1);
		(*nb_char)++;
	}
	else if (c == 'd' || c == 'i')
		ft_print_nbr(args, nb_char);
	else if (c == 'x' || c == 'X')
		ft_print_hex(args, c, nb_char);
	else if (c == 's')
		ft_print_str(args, nb_char);
	else if (c == 'p')
		ft_print_address(args, nb_char);
	else if (c == 'u')
		ft_print_unsigned(args, nb_char);
}
