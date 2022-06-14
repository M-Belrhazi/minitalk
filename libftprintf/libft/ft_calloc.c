/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:10:31 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/11 11:50:55 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*p;
	char	*chr;
	int		temp;

	i = 0;
	if (nmemb != 0 && size != 0)
	{
		temp = size * nmemb;
		if (temp / nmemb != size)
			return (NULL);
	}
	p = malloc(nmemb * size);
	if (p == NULL)
		return (p);
	while (i < nmemb * size)
	{
		chr = p + i;
		*chr = 0;
		i++;
	}
	return (p);
}

/*
int	main()
{
	void *super;
	super = ft_calloc(2147483646, 2147483646);
	super = calloc(60, 0);
	return 0;
}
//CALLOC OK
*/
