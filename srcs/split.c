#include "cub3d.h"

int		ft_countword(char *s, char c)
{
	int	count;
	int	is_word;

	count = 0;
	is_word = 0;
	while (*s)
	{
		if (is_word == 0 && *s != c)
		{
			is_word = 1;
			count++;
		}
		else if (is_word == 1 && *s == c)
			is_word = 0;
		s++;
	}
	return (count);
}

int		ft_wordlen(char *s, char c)
{
	int len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_free(char **a)
{
	int	i;

	i = 0;
	if (a)
	{
		while (a[i])
		{
			free(a[i]);
			i++;
		}
		free(a);
	}
	return (NULL);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		nword;
	char	**arr;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	nword = ft_countword((char *)s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (nword + 1))))
		return (NULL);
	i = 0;
	while (i < nword)
	{
		while (*s == c && *s != '\0')
			s++;
		len = ft_wordlen((char*)s, c);
		if (!(arr[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (ft_free(arr));
		arr[i] = ft_strncpy(arr[i], s, len);
		arr[i][len] = 0;
		i++;
		s = s + len;
	}
	arr[i] = NULL;
	return (arr);
}
