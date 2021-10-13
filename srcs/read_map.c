#include "cub3d.h"

static void remake_map()
{
    int i = -1;
    int j = 0;
    if (!(cub.map = (char**)malloc(sizeof(char*) *(cub.row + 1))))
        ft_exit("Error during malloc!");
    while (++i < cub.row)
        cub.map[i] = (char*)malloc(sizeof(char) * (cub.col + 1));
    i = 0;
    while (i < cub.row)
    {
        j = 0;
        while (j < ft_strlen(cub.tmp_map[i]))
        {
            if (cub.tmp_map[i][j] == ' ')
                cub.map[i][j] = '*';
            else
                cub.map[i][j] = cub.tmp_map[i][j];
            j++;
        }
        while (j < cub.col)
        {
            cub.map[i][j] = '*';
            j++;
        }
        cub.map[i][j] = '\0';
        i++;
    }
    ft_free(cub.tmp_map);
}



void    check_col_border(char *str)
{
    while (*str != '\0')
    {
        if (*str != '1' && *str != '*')
            ft_exit("incorrect border1");
        str++;
    }
}

void     is_star(int i, int j)
{
    if ((i - 1 >= 0) && cub.map[i - 1][j] != '*' && cub.map[i - 1][j] != '1')
        ft_exit("invalid map1");
    if ((i + 1 < cub.row ) && cub.map[i + 1][j] != '*' && cub.map[i + 1][j] != '1')
        ft_exit("invalid map2");
    if ((j - 1 >= 0) && cub.map[i][j - 1] != '*' && cub.map[i][j - 1] != '1')
        ft_exit("invalid map3");
    if ((j + 1 < cub.col) && cub.map[i][j + 1] != '*' && cub.map[i][j + 1] != '1')
        ft_exit("invalid map4");
}

void    check_row_border(char *str, int col)
{
    int i;
    int j;

    i = 0;
    j = col - 1;
   
    while (str[i] == '*' && str[i] != '\0')
        i++;
    while (str[j] == '*' && j >= 0)
        j--;
    if (str[i] != '1' || str[j] != '1')
        ft_exit("Incorrect border2");
    i++;

}

void    make_map()
{
    int j = 0;
    while (cub.tmp_map[j] != '\0')
    {
        if (cub.col < ft_strlen(cub.tmp_map[j]))
            cub.col = ft_strlen(cub.tmp_map[j]);
        j++;
    }
    while (cub.tmp_map[cub.row] != '\0')
        cub.row++;
    remake_map();
    check_map();
}