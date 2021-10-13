#include "cub3d.h"

void   set_cordinates()
{
    int i = 0;
    int j = 0;
    int i_s = 0;
    while (i < cub.row)
    {
        j = 0;
        while (j < cub.col && i_s < mlx.s_count)
        {
            if (cub.map[i][j] == '2')
            {
                sprites[i_s].y = j + 0.5;
                sprites[i_s].x = i + 0.5;
                i_s++; 
            }
            j++;
        }
        i++;
    }
}

void    sortSprites()
{
    int i,  j;
    t_sprite key;

    for (i = 1; i < mlx.s_count; i++)
    {
        key = sprites[i];
        j = i - 1;
        while (j >= 0 && sprites[j].distance < key.distance) {
            sprites[j + 1] = sprites[j];
            j = j - 1;
        }
        sprites[j + 1] = key;
    }
}

void make_sprites(double *BUFFER)
{
    sprites = (t_sprite*)malloc(sizeof(t_sprite) * mlx.s_count);
    set_cordinates();
    for(int i = 0; i < mlx.s_count; i++)
        sprites[i].distance = ((mlx.posX - sprites[i].x) * (mlx.posX - sprites[i].x) + (mlx.posY - sprites[i].y) * (mlx.posY - sprites[i].y));
    sortSprites();
    for(int i = 0; i < mlx.s_count; i++)
    {
      double spriteX = sprites[i].x - mlx.posX;
      double spriteY = sprites[i].y - mlx.posY;


      double invDet = 1.0 / (mlx.planeX * mlx.dirY - mlx.dirX * mlx.planeY);

      double transformX = invDet * (mlx.dirY * spriteX - mlx.dirX * spriteY);
      double transformY = invDet * (-mlx.planeY * spriteX + mlx.planeX * spriteY);

      int spriteScreenX = (int)((cub.win_w_h[0] / 2) * (1 + transformX / transformY));

      int spriteHeight = abs((int)(cub.win_w_h[1] / (transformY)));
      int drawStartY = -spriteHeight / 2 + cub.win_w_h[1] / 2;
      int drawEndY = spriteHeight / 2 + cub.win_w_h[1] / 2;
      if(drawStartY < 0)
        drawStartY = 0;
      if(drawEndY >= cub.win_w_h[1])
        drawEndY = cub.win_w_h[1] - 1;

      int spriteWidth = abs((int)(cub.win_w_h[1] / (transformY)));
      int drawStartX = -spriteWidth / 2 + spriteScreenX;
      if(drawStartX < 0)
        drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= cub.win_w_h[0])
        drawEndX = cub.win_w_h[0] - 1;
      for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
        int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texSize / spriteWidth) / 256;
        if(transformY > 0 && stripe > 0 && stripe < cub.win_w_h[0] && transformY < BUFFER[stripe])
        for(int y = drawStartY; y < drawEndY; y++) 
        {
          int d = (y) * 256 - cub.win_w_h[1] * 128 + spriteHeight * 128;
          int texY = ((d * texSize) / spriteHeight) / 256;
          int color = get_color(&cub.S_texture, texX, texY);
          if((color & 0x00FFFFFF) != 0)
            my_mlx_pixel_put(&cub.data, stripe, y, color);
        }
      }
    }
    free(sprites);
}