/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:23:03 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/09 16:56:28 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long int	num;
	int			i;
	int			sign;

	num = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	return ((int)(num * sign));
}

/*
#include "stdio.h"

int	main(void)
{
	printf("%d : %d\n", ft_atoi("super"), atoi("super"));
	printf("%d : %d\n", ft_atoi(""), atoi(""));
	printf("%d : %d\n", ft_atoi("-+0"), atoi("-+0"));
	printf("%d : %d\n", ft_atoi(" \t\v\n  -+45shlhj87"),\
	atoi("  \t\v\n  -+45;lhh;lhl87"));
	printf("%d : %d\n", ft_atoi("12457845"), atoi("12457845"));
	printf("%d : %d\n", ft_atoi("312"), atoi("312"));
	printf("%d : %d\n", ft_atoi("200000000000"), atoi("200000000000"));
	printf("%d\n", atoi(NULL));
	printf("%d\n", ft_atoi(NULL));
	return (0);
}
//ATOI OK
*/
