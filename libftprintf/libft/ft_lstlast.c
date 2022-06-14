/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:36:39 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/10 20:50:14 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (lst == NULL)
		return (NULL);
	last = lst;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

/*
int	main(void)
{
		t_list	*list, *node2, *node3, *node4;

	list = ft_lstnew("super");
	node2 = ft_lstnew("popo");
	node3 = ft_lstnew("lolo");
	node4 = ft_lstnew("jojo");

//	ft_lstadd_back(&list, node2);
//	ft_lstadd_back(&list, node3);
//	ft_lstadd_back(&list, node4);
	printf("%s\n", (char *)ft_lstlast(list)->content);
	return (0);
}
*/
