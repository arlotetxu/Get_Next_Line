/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:38:50 by jflorido          #+#    #+#             */
/*   Updated: 2022/12/05 12:42:01 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
 * @DESCRIPTION
 * ****************************************************************************
 * Function that reads a file considering the BUFFER_SIZE varible (bytes to
 * read) defined in the header file (.h) and stores the content in the array
 * "buff".After each reading process, the function stores the read 
 * characters in the "aux" STATIC VARIABLE.
 * The functions continues until a '\n' character is found or no charater is
 * read.
 * WARNING: the read function keeps the last position you read.
 * That means that if you read 14 bytes, the next read iteration will start
 * in the 15 byte. For that reason it is needed a STATIC VARIBLE where to
 * keep the remaining characters in after a '/n' character is found.
 *
 * @param fd file descriptor
 * @param aux This is the string that will be returned.
 * 
 * @return a pointer to a string.
 *
 * @TIP --> add function system("leaks a.out") in a point you want to check
 * memory leaks
 */
char	*ft_read_file(int fd, char *aux)
{
	char	*buff;
	int		check;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	check = 1;
	while (!ft_strchr(aux, '\n') && check != 0)
	{
		check = read(fd, buff, BUFFER_SIZE);
		if (check == 0)
			break ;
		if (check == -1)
		{
			free (aux);
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
* @DESCRIPTION
* *****************************************************************************
* Function that receives a string with a '\n' character and cut the string
* from the beginning to the firstocurrence of '\n'. The remaining characters
* are kept in the STATIC VARIABLE "aux".
*
* @param fd file descriptor
* 
* @return A pointer to a string with a line.
*/
char	*get_next_line(int fd)
{
	static char	*aux;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	aux = ft_read_file(fd, aux);
	if (!aux)
		return (NULL);
	line = ft_substr_line(aux);
	if ((ft_strlen(aux) - ft_strlen(line)) == 0)
	{
		free (aux);
		aux = NULL;
		return (line);
	}
	aux = ft_substr_aux(aux);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*test;

// 	fd = open("testing.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("File open error");
// 		return (0);
// 	}
// 	else
// 	test = get_next_line(fd);
// 	printf("Testing first result: %s\n", test);
// 	free (test);
// 	test = get_next_line(fd);
// 	printf("Testing second result: %s\n", test);
// 	test = get_next_line(fd);
// 	printf("Testing third result: %s\n", test);
// 	test = get_next_line(fd);
// 	printf("Testing fourth result: %s\n", test);
// 	test = get_next_line(fd);
// 	printf("Testing fifth result: %s\n", test);
// 	return (0);
// }