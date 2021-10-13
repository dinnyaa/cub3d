#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		ft_return (char *str);
char	*get_next_line_string(int fd, char **line, int row_count);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
int	    ft_strlen(const char *s);
void	*ft_memmove(void *dest, const void *src, size_t len);

#endif
