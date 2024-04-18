/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:49:11 by rumachad          #+#    #+#             */
/*   Updated: 2023/11/09 14:59:29 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* void	ft_lstdelone(t_list	*lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
} */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst)
	{
		if (*lst)
		{
			temp = *lst;
			while (*lst != NULL)
			{
				temp = temp->next;
				ft_lstdelone(*lst, del);
				*lst = temp;
			}
		}
	}
}
