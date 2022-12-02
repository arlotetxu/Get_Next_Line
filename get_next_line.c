/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:38:50 by jflorido          #+#    #+#             */
/*   Updated: 2022/12/02 19:02:36 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
 * Function that reads the file considering the BUFFER_SIZE size
 * define in the header (.h) file and stores the content in the array buff.
 * WARNING: the read function keeps the last position you read.
 * That means that if you read 14 bytes, the next read will start
 * in the 15 byte. For that reason it is needed a static variable where to
 * keep the remaining characters after a /n character is found.
 
GET NEXT LINE ARITZ
 */
char	*ft_read_file(int fd, char *aux)
{
	char	*buff;
	int		check;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	check = 1;
	while (!ft_strchr(aux, '\n') && check != 0)
	{
		check = read(fd, buff, BUFFER_SIZE);
		if (check == 0)
			break ;
			//return (aux);
		if (check == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[check] = '\0';
		aux = ft_strjoin_gnl(aux, buff);
	}
	free (buff);
	return (aux);
}

/*
* The function that controls the program execution.
* ALARM: How to know if you are reading the last line.
* We control this thanks to the value in the check variable
* that stores the number of bytes read excep for the first
* launch that has a 1 value.

GET NEXT LINE ARITZ
*/
char	*get_next_line(int fd)
{
	static char	*aux;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	aux = ft_read_file(fd, aux);
	if (!aux)
		return (NULL);
	while (aux[i] && aux[i] != '\n')
		i++;
	line = ft_substr(aux, 0, i);
	aux = ft_substr(aux, i + 1, ft_strlen(aux) - ft_strlen(line));
	return (line);
}

int	main(void)
{
	int		fd;
	char	*test;

	fd = open("testing_null.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("File open error");
		return (0);
	}
	else
	test = get_next_line(fd);
	printf("Testeando resultado: %s\n", test);
	test = get_next_line(fd);
	printf("Testeando segundo resultado: %s\n", test);
	test = get_next_line(fd);
	printf("Testeando tercer resultado: %s\n", test);
	return (0);
}