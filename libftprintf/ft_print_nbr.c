/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:56:26 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/21 14:56:57 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_nbr(va_list args, int *nb_char)
{
	int	nb;

	nb = va_arg(args, int);
	ft_putnbr_printf_fd(nb, 1, nb_char);
}
