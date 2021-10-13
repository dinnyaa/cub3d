#include "cub3d_bonus.h"

int game_bonus()
{
    read_keys();
    ft_clear();
    ft_raycasting_bonus();
    mlx_put_image_to_window(mlx.ptr, mlx.window, cub.data.img, 0, 0);
    mlx_do_sync(mlx.ptr);
    return (0);
}

void turn_off(int sigint)
{
    (void)sigint;
    system("killall afplay");
    ft_exit("Bye Bye");
}