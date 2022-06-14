/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:22:36 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/06 14:13:24 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*s1_ch;
	unsigned char		*s2_ch;

	s1_ch = (unsigned char *)s1;
	s2_ch = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (*(s1_ch + i) != *(s2_ch + i))
			return (*(s1_ch + i) - *(s2_ch + i));
		i++;
	}
	return (0);
}
