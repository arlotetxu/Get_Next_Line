/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:36:10 by jflorido          #+#    #+#             */
/*   Updated: 2022/12/02 19:03:09 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*		
* DESCRIPTION
* ***********
* The strchr() function locates the first given character in a string.
* It mimics the strchr function from the string library.
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
* ***********
* The ft_substr creates a substring starting from the start value
* parameter and with the total size of 'len' parameter
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	i;
	char	*ptr;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	i = 0;
	j = 0;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j <= len)
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

/*		
* DESCRIPTION
* ***********
* The function ft_strlen() mimics the behavior of the strlen() function from
* string C library. Both functions returns the number of characters that
* precede the terminating NULL character in a string.
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
* ***********
* The ft_strjoin() function concatenates 2 different string allocating
* enought memory in the system. If there are not strings or memory
* allocation fails, the function return null. Otherwise, the function
* return a pointer to the final string.
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
	if (!s1 || !s2)
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

