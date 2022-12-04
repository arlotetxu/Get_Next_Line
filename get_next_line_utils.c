/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:36:10 by jflorido          #+#    #+#             */
/*   Updated: 2022/12/04 10:56:12 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*		
* DESCRIPTION
* *****************************************************************************
* The strchr() function locates the first given character in a string.
* It mimics the strchr function from the string library.
*
* @param "s" as the original string.
* @param "c" as the character to be located in "s" string.
* 
* @return A pointer to a string with remaining characters.
*/
int	ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	if (!s)
		return (0);
	str = (char *)s;
	i = 0;
	if (((char)c) == '\0')
		return (i);
	while (str[i] != '\0')
	{
		if (str[i] == ((char)c))
			return (i);
		i++;
	}
	return (0);
}

/*		
* DESCRIPTION
* *****************************************************************************
* The ft_substr_line creates a substring starting from the beginning until 
* a '\n' is found.
*
* @param ""s" as the original string.
* 
* @return A pointer to a string with the first line.
*/

char	*ft_substr_line(char *s)
{
	size_t	i;
	char	*ptr;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	ptr = malloc(sizeof(char) * (i + 2));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		ptr[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/* 
 * DESCRIPTION
 * *****************************************************************************
 * Create a substring from the '\n' first ocurrence till the end of the original
 * string.
 * 
 * @param ""s" as the original string.
 * 
 * @return A pointer to a string with remaining characters.
 */
char	*ft_substr_aux(char *s)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] && s[i] == '\n')
		i++;
	ptr = malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (ptr == NULL)
		return (NULL);
	j = 0;
	while (s[i] && s[i] != '\0')
		ptr[j++] = s[i++];
	ptr[j] = '\0';
	free (s);
	return (ptr);
}

/*		
* DESCRIPTION
* *****************************************************************************
* The function ft_strlen() mimics the behavior of the strlen() function from
* string C library. Both functions returns the number of characters that
* precede the terminating NULL character in a string.
*
* @param "s" as the original string.
* 
* @return "n" as the number of character in the string.
*/

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	if (!s)
		return (0);
	while (s[n] != '\0')
		n++;
	return (n);
}

/*
* DESCRIPTION
* *****************************************************************************
* The ft_strjoin_gnl() function concatenates 2 different string allocating
* enought memory in the system. If there are not strings or memory
* allocation fails, the function return null. Otherwise, the function
* return a pointer to the final string.
*
* @param "s1" as first string.
* @param "s2" as second string
* 
* @return "n_str" as the new string concatenated.
*/

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*n_str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc (1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	n_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (n_str == NULL)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i])
			n_str[i] = s1[i];
	j = 0;
	while (s2[j])
		n_str[i++] = s2[j++];
	n_str[i++] = '\0';
	free(s1);
	return (n_str);
}
