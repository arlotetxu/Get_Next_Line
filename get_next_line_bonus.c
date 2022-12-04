/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:38:50 by jflorido          #+#    #+#             */
/*   Updated: 2022/12/04 12:12:58 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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
	static char	*aux[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	aux[fd] = ft_read_file(fd, aux[fd]);
	if (!aux[fd])
		return (NULL);
	line = ft_substr_line(aux[fd]);
	if ((ft_strlen(aux[fd]) - ft_strlen(line)) == 0)
	{
		free (aux[fd]);
		aux[fd] = NULL;
		return (line);
	}
	aux[fd] = ft_substr_aux(aux[fd]);
	return (line);
}

// int	main(void)
// {
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	int		counter;
// 	char	*test;

// 	fd1 = open("testing1.txt", O_RDONLY);
// 	fd2 = open("testing2.txt", O_RDONLY);
// 	fd3 = open("testing3.txt", O_RDONLY);

// 	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
// 		printf("Error opening the file");
// 	else
// 	{
// 		counter = 0;
// 		while (counter < 4)
// 		{
// 			test = get_next_line(fd1);
// 			printf("Testing result fd1: %s\n", test);
// 			free (test);
// 			test = get_next_line(fd2);
// 			printf("Testing result fd2: %s\n", test);
// 			free (test);
// 			test = get_next_line(fd3);
// 			printf("Testing result fd3: %s\n", test);
// 			free (test);
// 			counter++;
// 		}
// 	}
// 	return (0);
// }