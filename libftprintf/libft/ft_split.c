/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:53:45 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/11 12:59:27 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count(char const *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (s[0] == 0 || (s[0] == c && ft_strlen(s) == 1))
		return (count);
	if (s[0] != c)
		count++;
	while (i < ft_strlen(s) - 1)
	{
		if (s[i] == c && s[i + 1] != c)
		{
			count++;
		}
		i++;
	}
	return (count);
}

static	char	**ft_fillstrs(char const *s, char c, char **strs, int count)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (j < count)
	{
		k = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			strs[j][k] = s[i];
			i++;
			k++;
		}
		strs[j][k] = '\0';
		if (s[i] == 0)
			return (strs);
		i++;
		j++;
	}
	return (strs);
}

static	int	ft_size(char const *s, char c, int *j)
{
	int	k;
	int	i;

	i = *j;
	while (s[i] == c)
		i++;
	k = i;
	while (s[i] && s[i] != c)
		i++;
	*j = i;
	return (i - k + 1);
}

static	char	**ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i <= count)
	{
		free(strs[i]);
		i++;
	}
	strs = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	int			count;
	char		**strs;
	int			i;
	int			*j;
	int			e;

	count = ft_count(s, c);
	strs = malloc(sizeof(char *) * (count + 1));
	if (strs == NULL)
		return (strs);
	strs[count] = NULL;
	i = 0;
	e = 0;
	j = &e;
	while (i < count)
	{
		strs[i] = malloc(sizeof(char) * (ft_size(s, c, j)));
		if (strs[i] == NULL)
			return (ft_free(strs, count));
		i++;
	}
	return (ft_fillstrs(s, c, strs, count));
}

/*
#include <stdio.h>

int	main()
{
	int	i;
	char	**str = ft_split("  supehjkgmarche sok sueprhkga\
	 fskhdhff olahsjhf hsyidugfisdf      ", 'f');

	i = 0;
	while (str[i])
	{
		printf("str[%d] = %s\n", i, str[i]);
		i++;
	}
	return (0);
}
*/
