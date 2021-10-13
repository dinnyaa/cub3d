#include "cub3d_bonus.h"

void    parsing_texture_bonus(char *line, t_check *check)
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
        cub.f_texture.path = get_path(line + 2);
    else if (*line == 'C' && (++check->count_c == 1))
        cub.c_texture.path = get_path(line + 2);     
}

void    parsing_bonus(char *argv)
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
            parsing_texture_bonus(line, check);
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
