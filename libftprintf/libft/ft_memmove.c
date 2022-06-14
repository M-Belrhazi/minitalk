/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:19:54 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/08 15:34:13 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	if (src > dest)
	{
		while (i < n)
		{
			temp = (unsigned char *)(src + i);
			*(unsigned char *)(dest + i) = *temp;
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			temp = (unsigned char *)(src + (i - 1));
			*(unsigned char *)(dest + (i - 1)) = *temp;
			i--;
		}
	}
	return (dest);
}
