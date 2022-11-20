/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:38:50 by jflorido          #+#    #+#             */
/*   Updated: 2022/11/20 18:38:54 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


/*
 * Function that reads the file considering the BUFFER_SIZE size
 * define in the header (.h) file and stores the content in the array buff.
 * WARNING: the read function keeps the last position you read.
 * That means that if you read 14 bytes, the next read will start
 * in the 15 byte
 */
char	*ft_read_file(int fd, char *aux, int *check)
{
	char		*buff;

	/* Reading the file and storing information in buff array */
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	*check = read(fd, buff, BUFFER_SIZE);
	//printf("Data stored in BUFF: %s\n", buff);
	aux = ft_strjoin_gnl(aux, buff);
	free(buff);
	buff = NULL;
	//printf("Data stored in AUX: %s\n", aux);
	return (aux);
}

/* 
  The function that controls the program execution.
  ALARM: How to know if you are reading the last line.
  We control this thaks to the value in the check variable */
char *get_next_line(int fd)
{
	static char *aux;
	char 		*line;
	int 		i;
	int			check;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	check = 1;
	while (check != 0 && ft_strchr(aux, '\n') == 0)
	{
		aux = ft_read_file(fd, aux, &check);
	}
	while (aux[i] && aux[i] != '\n')
		i++;
	line = ft_substr(aux, 0, i);
	//printf("Data Stored in LINE: %s\n", line);
	aux = ft_substr(aux, i + 1, ft_strlen(aux) - ft_strlen(line));
	//printf("Data stored in AUX2: %s\n", aux);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*test;

	fd = open("testing.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("File open error");
		return (0);
	}
	else
		//printf("File descriptor nbr: %d\n", fd);
	test = get_next_line(fd);
	printf("Testeando resultado: %s\n", test);
	test = get_next_line(fd);
	printf("Testeando segundo resultado: %s\n", test);
	test = get_next_line(fd);
	printf("Testeando tercer resultado: %s\n", test);
	return (0);
}


