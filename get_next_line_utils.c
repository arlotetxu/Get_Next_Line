//
// Created by Jose Manuel Florido Perena on 10/31/22.
//

#include "get_next_line.h"

/*		DESCRIPTION
		***********
		The strchr() function locates the first given character in a string.
		It mimics the strchr function from the string library.		*/
int	ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	if (!s)
		return (0);
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ((char)c))
			return (i);
		i++;
	}
	if (((char)c) == '\0')
		return (i);
	return (0);
}

/*		DESCRIPTION
  		***********
  		The ft_substr creates a substring starting from the start value
  		parameter and with the total size of 'len' paramete/*   Updated: 2022/11/20 13:51:06 by jflorido         ###   ########.fr       */i;
	size_t	j;
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
		if (i >= start && j < len)
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

/*		DESCRIPTION
		***********
		The function ft_strlen() mimics the behavior of the strlen() function from
		string C library. Both functions returns the number of characters that
		precede the terminating NULL character in a string.		*/

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

/*		DESCRIPTION
		***********
		The ft_strjoin() function concatenates 2 different string allocating
		enought memory in the system. If there are not strings or memory
		allocation fails, the function return null. Otherwise, the function
		return a pointer to the final string. */

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*n_str;
	size_t	len;
	int	i;
	int	j;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	//printf("Tamaño len %zu\n", len);
	/*if (!s1 || !s2)
		return (NULL);*/
	n_str = malloc(sizeof(char) * (len + 1));
	if (n_str == NULL)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			n_str[i] =  s1[i];
			i++;
			//printf("s1: %c\n", s1[i]);
			//printf("n_str: %c\n", n_str[i]);
		}
		
	}
	j = 0;
	while (s2[j])
	{
		n_str[i] = s2[j];
		j++;
		i++;
		//printf("s2: %c\n", s2[j]);
		//printf("n_str: %c\n", n_str[i]);
	}
	//printf("Valor de i %d\n", i);
	n_str[i] = '\0';
	//printf("n_str: %s\n", n_str);
	return (n_str);
}