/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:08:04 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/10 12:10:39 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		k;
	int		j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		k = 0;
		j = 0;
		while (big[i + j] == little[k] && (i + j) < len && little[k])
		{
			k++;
			j++;
			if (little[k] == '\0')
			{
				return ((char *)(big + i + j - k));
			}
		}
		i++;
	}
	return (NULL);
}

//regle par return NULL, ca fait une erreur mais cest normal
/*
#include "stdio.h"

int	main(void)
{
	char haystack[30] = "aaabcabcd";

	printf("%s\n", ft_strnstr(haystack, "abcd", 90));
	return (0);
}
//STRRCHR OK OKOKOKOKOK
*/
