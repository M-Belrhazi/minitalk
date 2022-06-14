/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:15:46 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/06/13 16:46:27 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_fillsuperstr(char *s1, char *s2, char *superstr)
{
	int	i;
	int	k;

	i = 0;
	while (s1[i])
	{
		superstr[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k])
	{
		superstr[i] = s2[k];
		i++;
		k++;
	}
	free(s1);
	free(s2);
	return (superstr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		count;
	char	*superstr;

	i = 0;
	while (s1[i])
		i++;
	count = i;
	i = 0;
	while (s2[i])
		i++;
	count += i + 1;
	superstr = malloc(sizeof(char) * count);
	if (superstr == NULL)
		return (NULL);
	superstr[count - 1] = '\0';
	return (ft_fillsuperstr(s1, s2, superstr));
}
