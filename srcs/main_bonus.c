#include "cub3d_bonus.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        ft_exit("Error: Only one argument is needed!");
    signal(SIGINT, turn_off);
    init();
    parsing_bonus(argv[1]);
    make_map();
    mlx.ptr = mlx_init();
    set_mlx_images();
    set_mlx_images_bonus();
    set_mlx_addresses();
    set_mlx_addresses_bonus();
    mlx.window = mlx_new_window(mlx.ptr, cub.win_w_h[0], cub.win_w_h[1], "CUB3D_BONUS");
    mlx_put_image_to_window(mlx.ptr, mlx.window, cub.data.img, 0, 0);
    system("afplay ./music/song.mp3 & ");
    mlx_hook(mlx.window, 2, 1L<<0, key_press_bonus, &mlx.ptr);
    mlx_hook(mlx.window, 3, 1L<<1, key_release, &mlx.ptr);
    mlx_hook(mlx.window, 17, 1L<<17, ft_close, &mlx.ptr);
    mlx_loop_hook(mlx.ptr, game_bonus, &mlx);
    mlx_loop(mlx.ptr);
    return (0);
}