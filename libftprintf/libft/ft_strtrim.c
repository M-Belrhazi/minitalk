/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:25:51 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/10 14:59:14 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	*ft_fillindexes_1(char const *s1, char const *set, int *indexes)
{
	int	i;
	int	k;
	int	found;

	i = 0;
	while (s1[i])
	{
		k = 0;
		found = 0;
		while (set[k])
		{
			if (s1[i] == set[k])
				found = 1;
			k++;
		}
		if (found == 0)
			break ;
		i++;
	}
	indexes[0] = i;
	return (indexes);
}

static	int	*ft_fillindexes_2(char const *s1, char const *set, int *indexes)
{
	int	i;
	int	k;
	int	found;

	i = (int)ft_strlen(s1) - 1;
	while (i >= 0)
	{
		k = 0;
		found = 0;
		while (set[k])
		{
			if (s1[i] == set[k])
				found = 1;
			k++;
		}
		if (found == 0)
			break ;
		i--;
	}
	if (i < 0)
		return (NULL);
	else
		indexes[1] = i;
	return (indexes);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		indexes[3];
	int		count;
	char	*trim;

	ft_fillindexes_1(s1, set, indexes);
	if (ft_fillindexes_2(s1, set, indexes) == NULL)
		count = 0;
	else
		count = indexes[1] - indexes[0] + 1;
	trim = malloc(sizeof(char) * (count + 1));
	if (trim == NULL)
		return (trim);
	trim[count] = '\0';
	if (count == 0)
		return (trim);
	i = indexes[0];
	indexes[2] = 0;
	while (i <= indexes[1])
	{
		trim[indexes[2]] = s1[i];
		indexes[2]++;
		i++;
	}
	return (trim);
}
