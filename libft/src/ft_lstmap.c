/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:39:50 by rumachad          #+#    #+#             */
/*   Updated: 2023/11/09 14:59:29 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = NULL;
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
} */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*first;

	if (f == NULL || lst == NULL || del == NULL)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (new == NULL)
		return (NULL);
	first = new;
	lst = lst->next;
	while (lst != NULL)
	{
		new->next = ft_lstnew(f(lst->content));
		if (new->next == NULL)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (first);
}
