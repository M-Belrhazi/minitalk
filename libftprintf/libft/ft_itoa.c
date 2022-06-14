/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:11:23 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/12 13:33:14 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_fillnb(int count, int sign, char *str, int n)
{
	int	num;
	int	i;

	str[count + sign] = '\0';
	if (sign == 1)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	i = 0;
	while (i < count)
	{
		str[count + sign - 1 - i] = (num % 10) + 48;
		num = num / 10;
		i++;
	}
	return (str);
}

static	char	*ft_max(int n)
{
	char	*str;

	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	str = ft_strdup("-2147483648");
	return (str);
}

char	*ft_itoa(int n)
{
	int		num;
	int		sign;
	int		count;
	char	*str;

	sign = 0;
	num = n;
	if (n == -2147483648 || n == 0)
		return (ft_max(n));
	if (n < 0)
	{
		sign = 1;
		num = n * (-1);
	}
	count = 0;
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	str = malloc(sizeof(char) * (count + sign + 1));
	if (str == NULL)
		return (str);
	return (ft_fillnb(count, sign, str, n));
}
