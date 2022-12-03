/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:29:46 by jflorido          #+#    #+#             */
/*   Updated: 2022/12/03 16:33:22 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

//put your function headers here
int		ft_strchr(const char *s, int c);
char	*ft_substr_line(char *s);
char	*ft_substr_aux(char *s);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_read_file(int fd, char *aux);
char	*get_next_line(int fd);

#endif
