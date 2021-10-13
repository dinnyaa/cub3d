#include "get_next_line.h"

char	*get_save(char *s)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (0);
	}
	if (!(result = malloc(sizeof(char) * ((ft_strlen(s) - i) + 1))))
		return (0);
	i++;
	while (s[i])
		result[j++] = s[i++];
	result[j] = '\0';
	free(s);
	return (result);
}

char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(line = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int		get_next_line(int fd, char **line)
{
	char		*buff;
	static char *s;
	int			rvalue;

	rvalue = 1;
	if (fd < 0 || !line)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (2))))
		return (-1);
	while (!ft_return(s) && rvalue != 0)
	{
		if ((rvalue = read(fd, buff, 1)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[rvalue] = '\0';
		s = ft_gnl_strjoin(s, buff);
	}
	free(buff);
	*line = get_line(s);
	s = get_save(s);
	free(*line);
	if (rvalue == 0) 
		return (0);
	return (1);
}

char	*get_next_line_string(int fd, char **line, int row_count)
{
	char		*buff;
	static char *s;
	int			rvalue;
	int			*array;
	int 		i;

	rvalue = 1;
	i = 0;
	array = malloc(sizeof(int) * row_count);
	if ((buff = malloc(sizeof(char) * (2))) != 0)
	{	
		while (!ft_return(s) && rvalue != 0)
		{
			if ((rvalue = read(fd, buff, 1)) == -1)
			{
				free(buff);
				return (NULL);
			}
			buff[rvalue] = '\0';
			s = ft_gnl_strjoin(s, buff);
		}
	}
	free(buff);
	*line = get_line(s);
	s = get_save(s);
	return (*line);
}