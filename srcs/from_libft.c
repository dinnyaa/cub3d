#include "cub3d.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int i;
	int number;

	i = 0;
	number = 0;
	while (str[i] == ' ' || str[i] == ',' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		ft_exit("Error: width or height size is incorrect");
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			number = number * 10 + (str[i] - '0');
			i++;
		}
		else
			ft_exit("write numbers only!");
	}
	return (number);
}
void	ft_putendl_fd(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (str1[i] || str2[i]))
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}


int		ft_length(int num)
{
	int count;

	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		ft_exit("it is negative number");
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*temp;
	size_t	i;
	size_t	l;

	l = ft_strlen(s);
	temp = (char*)malloc(sizeof(char) * (l + 1));
	i = 0;
	if (temp == NULL)
		return (NULL);
	while (s[i])
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

int		ft_isspace(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == ' ' ||  str[i] == '\t')
			return (1);
		i++;
	}
	return (0);
}

char *ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	if (dest == NULL)
		return (src);
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';

	return (dest);
}

char	*ft_strjoin(char *s1, char  *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		s3[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}

void ft_exit(char *s)
{
    ft_putendl_fd(s, 2);
    exit(0);
}
