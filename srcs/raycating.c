#include "cub3d.h"

void    ft_raycasting()
{
    int x = 0;
    double BUFFER[cub.win_w_h[0]];
    while (x < cub.win_w_h[0])
    {
        mlx.cameraX = 2 * x / (double)cub.win_w_h[0] - 1;
        mlx.rayDirX = mlx.dirX + mlx.planeX * mlx.cameraX;
        mlx.rayDirY = mlx.dirY + mlx.planeY * mlx.cameraX;
        mlx.mapX = (int)mlx.posX;
        mlx.mapY = (int)mlx.posY;

        mlx.deltaDistX = fabs(1 / mlx.rayDirX);
        mlx.deltaDistY = fabs(1 / mlx.rayDirY);

        int hit = 0;
        int side;

        if (mlx.rayDirX < 0)
        {
            mlx.stepX = -1;
            mlx.sideDistX = (mlx.posX - mlx.mapX) * mlx.deltaDistX;
        }
        else
        {
            mlx.stepX = 1;
            mlx.sideDistX = (mlx.mapX - mlx.posX + 1.0) * mlx.deltaDistX;
        }
        if (mlx.rayDirY < 0)
        {
            mlx.stepY = -1;
            mlx.sideDistY = (mlx.posY - mlx.mapY) * mlx.deltaDistY;
        }
        else
        {
            mlx.stepY = 1;
            mlx.sideDistY = (mlx.mapY - mlx.posY + 1.0) * mlx.deltaDistY;
        }
        while (hit == 0)
        {
            if(mlx.sideDistX < mlx.sideDistY)
            {
              mlx.sideDistX += mlx.deltaDistX;
              mlx.mapX += mlx.stepX;
              side = 0;
            }
            else
            {
              mlx.sideDistY += mlx.deltaDistY;
              mlx.mapY += mlx.stepY;
              side = 1;
            }
            if (cub.map[mlx.mapX][mlx.mapY] == '1')
                hit = 1;
        }
        if(side == 0)
            mlx.perpWallDist = (mlx.mapX - mlx.posX + (1 - mlx.stepX) / 2) / mlx.rayDirX;
        else
            mlx.perpWallDist = (mlx.mapY - mlx.posY + (1 - mlx.stepY) / 2) / mlx.rayDirY;
        
        int lineHeight = (int)(cub.win_w_h[1] / mlx.perpWallDist);
        int drawStart = -lineHeight / 2 + cub.win_w_h[1] / 2;
        int drawEnd = lineHeight / 2 + cub.win_w_h[1] / 2;
        if(drawStart < 0)
            drawStart = 0;
        if(drawEnd >= cub.win_w_h[1])
            drawEnd = cub.win_w_h[1] - 1;
        double wallX;
        if(side == 0)
            wallX = mlx.posY + mlx.perpWallDist * mlx.rayDirY;
        else
            wallX = mlx.posX + mlx.perpWallDist * mlx.rayDirX;
        wallX -= floor((wallX));
        int texX = (int)(wallX * (double)(texSize));
        if(side == 0 && mlx.rayDirX > 0)
            texX = texSize - texX - 1;
        if(side == 1 && mlx.rayDirY < 0)
            texX = texSize - texX - 1;
       
        double step = 1.0 * texSize / lineHeight;
        int color = 0;
        double texPos = (drawStart - cub.win_w_h[1] / 2 + lineHeight / 2) * step;

        for (int y = 0; y < drawStart; y++)
            my_mlx_pixel_put(&cub.data, x, y, rgb(cub.c_colors));
        for(int y = drawStart; y < drawEnd; y++)
        {
            int texY = (int)texPos & (texSize - 1);
            texPos += step;
            if (side == 0)
            {
                if (mlx.stepX > 0)
                    color = get_color(&cub.SO_texture, texX, texY);
                else
                    color = get_color(&cub.NO_texture, texX, texY);
            }
            else
            {
                if (mlx.stepY > 0)
                    color = get_color(&cub.WE_texture, texX, texY);
                else
                    color = get_color(&cub.EA_texture, texX, texY);
            }
            my_mlx_pixel_put(&cub.data, x, y, color);
        }
        for (int y = drawEnd; y < cub.win_w_h[1]; y++)
            my_mlx_pixel_put(&cub.data, x, y, rgb(cub.f_colors));
        BUFFER[x] = mlx.perpWallDist;
        x++;
    }
    make_sprites(BUFFER);
}