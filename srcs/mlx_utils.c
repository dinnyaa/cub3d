#include "cub3d.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int		get_color(t_data *data, int x, int y)
{
	return (*(int *)(data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8))));
}

int rgb(int *colors)
{
    return ((colors[0] << 16) + (colors[1] << 8) + colors[2]);
}

int ft_close()
{
    system("killall afplay");
    exit(0);
}

void    set_mlx_images()
{
    cub.data.img = mlx_new_image(mlx.ptr, cub.win_w_h[0], cub.win_w_h[1]);
    cub.S_texture.img = mlx_xpm_file_to_image(mlx.ptr, cub.S_texture.path,
                            &cub.S_texture.width, &cub.S_texture.height);
    cub.NO_texture.img = mlx_xpm_file_to_image(mlx.ptr, cub.NO_texture.path,
                            &cub.NO_texture.width, &cub.NO_texture.height);
    cub.SO_texture.img = mlx_xpm_file_to_image(mlx.ptr, cub.SO_texture.path,
                            &cub.SO_texture.width, &cub.SO_texture.height);
    cub.WE_texture.img = mlx_xpm_file_to_image(mlx.ptr, cub.WE_texture.path,
                            &cub.WE_texture.width, &cub.WE_texture.height);
    cub.EA_texture.img = mlx_xpm_file_to_image(mlx.ptr, cub.EA_texture.path,
                            &cub.EA_texture.width, &cub.EA_texture.height);
}

void set_mlx_addresses()
{
    cub.data.addr = mlx_get_data_addr(cub.data.img, &cub.data.bits_per_pixel,
                            &cub.data.line_length, &cub.data.endian);
    cub.S_texture.addr = mlx_get_data_addr(cub.S_texture.img, &cub.S_texture.bits_per_pixel,
                            &cub.S_texture.line_length, &cub.S_texture.endian);
    cub.SO_texture.addr = mlx_get_data_addr(cub.SO_texture.img, &cub.SO_texture.bits_per_pixel,
                            &cub.SO_texture.line_length, &cub.SO_texture.endian);
    cub.NO_texture.addr = mlx_get_data_addr(cub.NO_texture.img, &cub.NO_texture.bits_per_pixel,
                            &cub.NO_texture.line_length, &cub.NO_texture.endian);
    cub.WE_texture.addr = mlx_get_data_addr(cub.WE_texture.img, &cub.WE_texture.bits_per_pixel,
                            &cub.WE_texture.line_length, &cub.WE_texture.endian);
    cub.EA_texture.addr = mlx_get_data_addr(cub.EA_texture.img, &cub.EA_texture.bits_per_pixel,
                            &cub.EA_texture.line_length, &cub.EA_texture.endian);
}