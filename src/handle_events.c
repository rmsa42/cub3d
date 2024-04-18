/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:30:53 by rumachad          #+#    #+#             */
/*   Updated: 2024/04/18 12:01:02 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	handle_event(int keycode, t_mlx *mlx)
{
	/* printf("%d\n", keycode); */
	if (keycode == ESC)
		close_game(mlx);
	return (0);
}
