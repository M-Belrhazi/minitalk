/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:19:23 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/21 23:37:29 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
void	ft_forest(char c, va_list args, int *nb_char);
void	ft_print_address(va_list args, int *nb_char);
void	ft_print_hex(va_list args, char c, int *nb_char);
void	ft_putnbr_hex_fd(unsigned long nb, int fd, char *tab, int *nb_char);
void	ft_print_unsigned(va_list args, int *nb_char);
void	ft_putstr_printf_fd(char *s, int fd, int *nb_char);
void	ft_print_str(va_list args, int *nb_char);
void	ft_print_nbr(va_list args, int *nb_char);
void	ft_putnbr_printf_fd(int n, int fd, int *nb_char);
void	ft_write_nbr(int nb, int fd, int *nb_char);
void	ft_print_char(va_list args);

#endif
