/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:28:40 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/05/10 22:23:58 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*newlst;

	if (!lst || !f || !del)
		return (NULL);
	start = ft_lstnew((*f)(lst->content));
	newlst = start;
	if (start == NULL)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		start->next = ft_lstnew((*f)(lst->content));
		if (start->next == NULL)
		{
			continue ;
		}
		if (start->next->content == NULL)
			ft_lstdelone(start->next, del);
		lst = lst->next;
		start = start->next;
	}
	return (newlst);
}

/*
void	ft(void *super)
{
	super = "";
}

void	*ftcop(void *super)
{
	return (NULL);
}

int	main()
{
	t_list	*list = ft_lstnew("super");
	t_list	*node2 = ft_lstnew("coco");
	t_list	*node3 = ft_lstnew("popo");
	t_list	*last;

	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node3);
	last = ft_lstmap(list, &ftcop, &ft);
	printf("last = %p\n", last->next);
}
*/
