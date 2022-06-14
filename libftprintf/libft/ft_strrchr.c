/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:07:17 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/09 17:45:37 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (s[i] == (char)c)
		return ((char *)(s + i));
	while (i > 0)
	{
		if (s[i - 1] == (char)c)
			return ((char *)(s + i - 1));
		i--;
	}
	return (NULL);
}

/*
#include "string.h"
#include "stdio.h"

int	main(void)
{
	printf("%s\n", strrchr("supertmarche", 't' + 256 + 256));
	printf("%s\n", ft_strrchr("supertmarche", 't' + 256));
	return (0);
}
//STRRCHR OK
*/
