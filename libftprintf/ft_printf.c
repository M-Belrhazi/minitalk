/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:03:37 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/22 13:08:48 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	error_pct(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!(str[i + 1] == '%' || str[i + 1] == 'x'
					|| str[i + 1] == 'X' || str[i + 1] == 'c'
					|| str[i + 1] == 'i'
					|| str[i + 1] == 'd' || str[i + 1] == 's'
					|| str[i + 1] == 'u'
					|| str[i + 1] == 'p'))
			{
				return (-2);
			}
			if (str[i + 1] == '%')
				i++;
		}
		i++;
	}
	return (0);
}

static void	print_string(char *str, int i, unsigned int start, int *nb_char)
{
	write(1, &(str[start]), i - start);
	*nb_char += (i - start);
}

static void	dosomething(char *str, int i, va_list args, int *nb_char)
{
	unsigned int	start;

	start = i;
	while (str[i] != '%' && str[i])
	{
		i++;
	}
	if (i - (int)start > 0)
		print_string(str, i, start, nb_char);
	if (!str[i])
		return ;
	i++;
	ft_forest(str[i], args, nb_char);
	i++;
	dosomething(str, i, args, nb_char);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		error;
	int		nb_char;

	nb_char = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	if (str[0] == 0)
		return (0);
	error = error_pct((char *)str);
	if (error)
		return (error);
	dosomething((char *)str, 0, args, &nb_char);
	va_end(args);
	return (nb_char);
}

/*
int	main(void)
{
	char	c;
	char	*s;

	c = '9';
	s = NULL;
	printf("%d\n", printf("%% %c %p %s %s %p %d %i %u %X\n", c, &c,\
	"coucou tout le monde", s, s, -8, -9, -3000000000, 90000000000));
	printf("%d\n", ft_printf("%% %c %p %s %s %p %d %i %u %X\n", c, &c,\
	"coucou tout le monde", s, s, -8, -9, -3000000000, 90000000000));
	printf("%d\n", printf("l\n"));
	printf("%d\n", printf("l\n"));
	return (0);
}
*/
/*
int	count_nb_args(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if ((str[i + 1] == 'x'
					|| str[i + 1] == 'X' || str[i + 1] == 'c'
					|| str[i + 1] == 'i'
					|| str[i + 1] == 'd' || str[i + 1] == 's'
					|| str[i + 1] == 'u'
					|| str[i + 1] == 'p'))
				count++;
		}
		i++;
	}
	return (count);
}
*/
