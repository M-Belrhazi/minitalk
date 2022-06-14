/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:45:02 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/21 14:45:23 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr_printf_fd(char *s, int fd, int *nb_char)
{
	int	size;

	size = ft_strlen(s);
	write(fd, s, size);
	*nb_char = *nb_char + size;
}
