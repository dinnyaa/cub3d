#include "cub3d.h"

static void print_error_message(char *ext)
{
    ft_putstr_fd("Error, format isn't ", 2);
    ft_putstr_fd(ext, 2);
    exit(0);
}

void     check_map_name(char *string, char *ext)
{
    int i = 0;
    int len = ft_strlen(ext);
    while (string[i])
        i++;
    while (len--)
        i--;
    if (string[i] == '.')
    {
        if (ft_strncmp((string + i), ext, ft_strlen(ext)))
            print_error_message(ext);
    }
    else
        print_error_message(ext);
}

void    get_size(char *line, int *color, int n, char c)
{
    int     i;
    int     count;
    int     len;
    int     width;
    int     height;
    char    **arr;

    i = 0;
    count = 1;
    len = ft_strlen(line) + 1;
    while (*line == ' ')
    {    
        line++;
        count++;
    }
    arr = ft_split(line, c);
    while (i < n)
    {
        color[i] = ft_atoi(arr[i]);
        if(n == 3 && color[i] > 255)
            ft_exit("the number is too long");
        count += ft_length(color[i]);
        i++;
    }
    mlx_get_screen_size(&mlx.ptr, &width, &height);
    if (n == 2 && color[0] > width)
        color[0] = width;
    if (n == 2 && color[1] > height)
        color[1] = height;
    ft_free(arr);
    if (n == 2 && (count + 1) < len)
        ft_exit("too many arguments01");
    else if (n == 3 && (count + 2) < len)
        ft_exit("too many arguments02");
}

char*    get_path(char *line)
{
    char    *path;
    int     fd;

    while (*line == ' ')
        line++;
    if (ft_isspace(line))
        ft_exit("The path is not formated well!");
    path = ft_strdup(line);
    check_map_name(path, ".xpm");
    if ((fd = open(path, O_RDONLY)) == -1)
        ft_exit("This path doesn't exist!");
    else
        close(fd);    
    return (path);
}


void    parsing_texture(char *line, t_check *check)
{
    if (*line == 'R' && (++check->count_r == 1))
        get_size(++line, cub.win_w_h, 2, ' ');
    else if ((*line == 'N'&& *(line + 1) == 'O') && (++check->count_NO == 1))
        cub.NO_texture.path = get_path(line + 2);
    else if ((*line == 'S'&& *(line + 1) == 'O') && (++check->count_SO == 1))
        cub.SO_texture.path = get_path(line + 2);
    else if ((*line == 'W' && *(line + 1) == 'E') && (++check->count_WE == 1))
        cub.WE_texture.path = get_path(line + 2);
    else if ((*line == 'E' && *(line + 1) == 'A') && (++check->count_EA == 1))
        cub.EA_texture.path = get_path(line + 2);
    else if (*line == 'S' && (++check->count_S == 1))
        cub.S_texture.path = get_path(line + 2);
    else if (*line == 'F' && (++check->count_f == 1))
        get_size(++line, cub.f_colors, 3, ',');
    else if (*line == 'C' && (++check->count_c == 1))
        get_size(++line, cub.c_colors, 3, ',');
}

void    parsing(char *argv)
{
    int     fd;
    int     line_count;
    int     res;
    char    *line;
    char    *string;
    char    *tmp;
    t_check *check;

    line_count = 0;
    check = init_check();
    string = NULL;
    fd = open(argv, O_RDONLY);
    if (fd == -1)
        ft_exit("failed opening the file");
    check_map_name(argv, ".cub");
    while (line_count != 8 && get_next_line(fd, &line))
    {
        if (ft_strlen(line) == 0)
            continue;
        else
        {
            parsing_texture(line, check);
            ++line_count;
        }
    }
    while((res = get_next_line(fd, &line)) > 0)
    {
        if (ft_strlen(line) == 0)
            continue;
        else
            break;
    }
    while (res > 0)
    {  
        if (ft_strlen(line) == 0)
            ft_exit("empty lines are not allowed!");
        else
        {
            line = ft_strjoin(line, "\n");
            tmp = ft_strjoin(string, line);
            free(string);
            string = tmp;
        }
        res = get_next_line(fd, &line);
    }
    if (res == 0 && ft_strlen(line))
    {
        tmp = ft_strjoin(string, line);
        free(string);
        string = tmp;
    }
    else
        ft_exit("odd line");
    cub.tmp_map = ft_split(string, '\n');
    free(string);
    map_validation(check);
    close(fd);
}