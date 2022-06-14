/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:52:51 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/21 17:02:53 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_str(va_list args, int *nb_char)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		(*nb_char) += 6;
		return ;
	}
	ft_putstr_printf_fd(str, 1, nb_char);
}
