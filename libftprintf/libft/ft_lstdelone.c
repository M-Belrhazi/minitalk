/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:55:11 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/10 19:07:29 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}

/*
void	ft(void *super)
{
	super = "";
}

int	main()
{
	t_list	*list = ft_lstnew("super");
	t_list	*node2 = ft_lstnew("coco");
	t_list	*node3 = ft_lstnew("popo");
	t_list	*last;

	//size = ft_lstsize(lst);

	while(i -> len)
	lst = lst->next

	lst->next = NULL;
	len--;

	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node3);
	last = ft_lstlast(list);
	printf("%s\n", (char *)last->content);
	list->next = NULL;
	ft_lstdelone(last, &ft);
	last = ft_lstlast(list);
	printf("%s\n", (char *)last->content);
	ft_lstdelone(last, &ft);
}
*/
