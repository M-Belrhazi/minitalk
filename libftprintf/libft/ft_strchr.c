/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:05:53 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/09 17:44:48 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

/*
#include "string.h"
#include "stdio.h"

int	main(void)
{
	printf("%s\n", strchr("supertmarche", 't' + 257));
	printf("%s\n", ft_strchr("supertmarche", 't' + 257));
	return (0);
}
//STRCHR OK
*/
