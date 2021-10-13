#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int lenght;

	lenght = 0;
	if (!str)
		return (0);
	while (*str++ != '\0')
		lenght++;
	return (lenght);
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char *d;
	char *s;

	d = (char *)dest;
	s = (char *)src;
	if (dest == src)
		return (dest);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dest);
	}
	while (len--)
		*d++ = *s++;
	return (dest);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	len;
	char	*result;

	if (!s1 && !s2)
		return (0);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	len = len1 + len2 + 1;
	if (!(result = malloc(sizeof(char) * len)))
		return (0);
	ft_memmove(result, s1, len1);
	ft_memmove(result + len1, s2, len2);
	result[len - 1] = '\0';
	free((char *)s1);
	return (result);
}

int		ft_return(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
