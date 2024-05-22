/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:29:13 by jmarinho          #+#    #+#             */
/*   Updated: 2023/05/05 14:35:22 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_read_and_join(int fd, char *temp);
int		ft_strlen(char *str);
char	*ft_strchr(char *str, char line_break);
char	*ft_strjoin(char *temp, char *buffer);
char	*ft_get_line(char *temp);
char	*ft_new_temp(char *temp);

#endif
