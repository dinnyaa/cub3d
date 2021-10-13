#include "cub3d.h"


int key_press(int keycode)
{
    if (keycode == 53)
        ft_exit("Bye Bye");
    else if (keycode == 13)
        mlx.key.w = 1;
    else if (keycode == 1)
        mlx.key.s = 1;
    else if (keycode == 0)
        mlx.key.a = 1;
    else if (keycode == 2)
        mlx.key.d = 1;
    else if (keycode == 123)
        mlx.key.left = 1;
    else if (keycode == 124)
        mlx.key.right = 1;
    return (0);
}

int key_release(int keycode)
{
    if (keycode == 13)
        mlx.key.w = 0;
    else if (keycode == 1)
        mlx.key.s = 0;
    else if (keycode == 0)
        mlx.key.a = 0;
    else if (keycode == 2)
        mlx.key.d = 0;
    else if (keycode == 123)
        mlx.key.left = 0;
    else if (keycode == 124)
        mlx.key.right = 0;
    return (0);
}
