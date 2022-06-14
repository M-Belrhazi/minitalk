/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 23:35:34 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/10 19:40:47 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	int		size;

	size = ft_lstsize(*lst);
	while (size)
	{
		temp = *lst;
		*lst = temp->next;
		ft_lstdelone(temp, del);
		size--;
	}
	lst = NULL;
}

/*
void	ft(void *super)
{
	super = "";
}

int	main()
{
	t_list	*list, *node2, *node3, *node4;

	list = ft_lstnew("super");
	node2 = ft_lstnew("popo");
	node3 = ft_lstnew("lolo");
	node4 = ft_lstnew("jojo");

//	ft_lstadd_back(&list, node2);
//	ft_lstadd_back(&list, node3);
//	ft_lstadd_back(&list, node4);

	ft_lstclear(&list, &ft);
	return (0);
}
*/
