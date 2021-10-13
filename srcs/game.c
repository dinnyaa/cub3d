#include "cub3d.h"

void ft_clear()
{
    int i = 0;
    int j;

    while (i < cub.win_w_h[1])
    {
        j = 0;
        while (j < cub.win_w_h[0])
        {
            my_mlx_pixel_put(&cub.data, j, i, 0x00000000);
            j++;
        }
        i++;
    }
}

int game()
{
    read_keys();
    ft_clear();
    ft_raycasting();
    mlx_put_image_to_window(mlx.ptr, mlx.window, cub.data.img, 0, 0);
    mlx_do_sync(mlx.ptr);
    return (0);
}