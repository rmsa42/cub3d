/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 00:48:27 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/04 11:50:07 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	elim_obj(t_list **head, t_list *elim_obj)
{
	t_list	*temp;

	temp = *head;
	if (*head == elim_obj)
	{
		*head = elim_obj->next;
		obj_destructor(elim_obj);
		return ;
	}
	while (temp->next && temp->next != elim_obj)
		temp = temp->next;
	if (temp->next == NULL)
		return ;
	temp->next = elim_obj->next;
	obj_destructor(elim_obj);
	elim_obj = NULL;
}

double	time_passed(struct timespec *last, struct timespec *current)
{
	return ((current->tv_sec - last->tv_sec)
		+ (current->tv_nsec - last->tv_nsec) / 1e9);
}

void	update_time(struct timespec *time)
{
	clock_gettime(CLOCK_MONOTONIC, time);
}
