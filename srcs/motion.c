#include "cub3d.h"

void read_keys()
{
    if(mlx.key.w)
    {
      if(cub.map[(int)((mlx.posX) + mlx.dirX * mlx.moveSpeed)][(int)(mlx.posY)] == '0')
        mlx.posX += mlx.dirX * mlx.moveSpeed;
      if(cub.map[(int)(mlx.posX)][(int)((mlx.posY) + mlx.dirY * mlx.moveSpeed)] == '0')
        (mlx.posY) += mlx.dirY * mlx.moveSpeed;
    }
    if(mlx.key.s)
    { 
      if(cub.map[(int)(mlx.posX - mlx.dirX * mlx.moveSpeed)][(int)(mlx.posY)] == '0')
        mlx.posX -= mlx.dirX * mlx.moveSpeed;
      if(cub.map[(int)(mlx.posX)][(int)(mlx.posY - mlx.dirY * mlx.moveSpeed)] == '0')
        mlx.posY -= mlx.dirY * mlx.moveSpeed;
    }
    if(mlx.key.d)
    { 
      if(cub.map[(int)(mlx.posX + mlx.dirY * mlx.moveSpeed)][(int)(mlx.posY)] == '0')
        mlx.posX += mlx.dirY * mlx.moveSpeed;
      if(cub.map[(int)(mlx.posX)][(int)(mlx.posY - mlx.dirX * mlx.moveSpeed)] == '0')
        mlx.posY -= mlx.dirX * mlx.moveSpeed;
    }
    if(mlx.key.a)
    { 
      if(cub.map[(int)(mlx.posX - mlx.dirY * mlx.moveSpeed)][(int)(mlx.posY)] == '0')
        mlx.posX -= mlx.dirY * mlx.moveSpeed;
      if(cub.map[(int)(mlx.posX)][(int)(mlx.posY + mlx.dirX * mlx.moveSpeed)] == '0')
        mlx.posY += mlx.dirX * mlx.moveSpeed;
    }
    if(mlx.key.right)
    {
      double oldDirX = mlx.dirX;
      mlx.dirX = mlx.dirX * cos(-mlx.rotSpeed) - mlx.dirY * sin(-mlx.rotSpeed);
      mlx.dirY = oldDirX * sin(-mlx.rotSpeed) + mlx.dirY * cos(-mlx.rotSpeed);
      double oldPlaneX = mlx.planeX;
      mlx.planeX = mlx.planeX * cos(-mlx.rotSpeed) - mlx.planeY * sin(-mlx.rotSpeed);
      mlx.planeY = oldPlaneX * sin(-mlx.rotSpeed) + mlx.planeY * cos(-mlx.rotSpeed);
    }
    if(mlx.key.left)
    {
      double oldDirX = mlx.dirX;
      mlx.dirX = mlx.dirX * cos(mlx.rotSpeed) - mlx.dirY * sin(mlx.rotSpeed);
      mlx.dirY = oldDirX * sin(mlx.rotSpeed) + mlx.dirY * cos(mlx.rotSpeed);
      double oldPlaneX = mlx.planeX;
      mlx.planeX = mlx.planeX * cos(mlx.rotSpeed) - mlx.planeY * sin(mlx.rotSpeed);
      mlx.planeY = oldPlaneX * sin(mlx.rotSpeed) + mlx.planeY * cos(mlx.rotSpeed);
    }
}