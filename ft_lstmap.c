/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:39:11 by ptheo             #+#    #+#             */
/*   Updated: 2024/04/05 18:39:11 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*current;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = (t_list *) malloc(ft_lstsize(lst) * sizeof(t_list));
	if (!new_lst)
		return (NULL);
	current = new_lst;
	while (lst != NULL)
	{
		if (lst->next != NULL)
			*current = (t_list){.content = f(lst->content),
				.next = current + 1};
		else
			*current = (t_list){.content = f(lst->content), .next = NULL};
		lst = lst->next;
		current++;
	}
	ft_lstclear(&lst, del);
	return (new_lst);
}
