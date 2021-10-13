#include "cub3d.h"

void    check_map()
{
    int i = 0;
    int j = 0;
    int player_count = 0;
    while (i < cub.row)
    {
        if (i == 0 || i == cub.row - 1)
            check_col_border(cub.map[i]);
        else
            check_row_border(cub.map[i], cub.col);
        j = 0;
        while (cub.map[i][j] != '\0')
        {
            if(cub.map[i][j] == '*')
                is_star(i , j);
            else if (cub.map[i][j] == 'S' || cub.map[i][j] == 'N'
            || cub.map[i][j] == 'E' || cub.map[i][j] == 'W')
            {
                player_count++;
                set_player_pos(j, i);
                set_player_dir_plane(cub.map);
            }
            else if (cub.map[i][j] == '2')
                mlx.s_count++;
            else if (cub.map[i][j] != '0' && cub.map[i][j] != '1')
                ft_exit("Invalid characters!");
            j++;
        }
        i++;
    }
    if (player_count != 1)
        ft_exit("Error with player positions!");
}

void    set_player_pos(int x, int y)
{
    cub.player_view = cub.map[y][x];
    mlx.posY = (double)x + 0.5;
    mlx.posX = (double)y + 0.5;
}

void    set_player_dir_plane(char **map)
{
    
    if (map[(int)(mlx.posX - 0.5)][(int)(mlx.posY - 0.5)] == 'N')
    {
        mlx.dirX = -1.0;
        mlx.dirY = 0.0;
        mlx.planeX = 0.0;
        mlx.planeY = 0.66;
    }
    else if (map[(int)(mlx.posX - 0.5)][(int)(mlx.posY - 0.5)] == 'S')
    {
        mlx.dirX = 1.0;
        mlx.dirY = 0.0;
        mlx.planeX = 0.0;
        mlx.planeY = -0.66;
    }
    else if (map[(int)(mlx.posX - 0.5)][(int)(mlx.posY - 0.5)] == 'E')
    {
        mlx.dirX = 0.0;
        mlx.dirY = 1.0;
        mlx.planeX = 0.66;
        mlx.planeY = 0.0;
    }
    else if (map[(int)(mlx.posX - 0.5)][(int)(mlx.posY - 0.5)] == 'W')
    {
        mlx.dirX = 0.0;
        mlx.dirY = -1.0;
        mlx.planeX = -0.66;
        mlx.planeY = 0.0;
    }
    else
        ft_exit("Error with player pos\n");
    map[(int)(mlx.posX - 0.5)][(int)(mlx.posY - 0.5)] = '0';
}
