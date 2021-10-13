#include "cub3d_bonus.h"

void   set_mlx_images_bonus()
{
    cub.f_texture.img = mlx_xpm_file_to_image(mlx.ptr, cub.f_texture.path,
                            &cub.f_texture.width, &cub.f_texture.height);
    cub.c_texture.img = mlx_xpm_file_to_image(mlx.ptr, cub.c_texture.path,
                            &cub.c_texture.width, &cub.c_texture.height);
}

void set_mlx_addresses_bonus()
{
    cub.c_texture.addr = mlx_get_data_addr(cub.c_texture.img, &cub.c_texture.bits_per_pixel,
                            &cub.c_texture.line_length, &cub.c_texture.endian);
    cub.f_texture.addr = mlx_get_data_addr(cub.f_texture.img, &cub.f_texture.bits_per_pixel,
                            &cub.f_texture.line_length, &cub.f_texture.endian);
}