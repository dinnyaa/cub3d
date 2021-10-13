#ifndef CUB3D_H
#define CUB3D_H
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "./get_next_line/get_next_line.h"
#include "../mlx/mlx.h"
#define texSize 64

typedef struct	s_data
{
    char*       path;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
}				t_data;

typedef struct s_sprite
{
    double         x;
    double         y;
    int         order;
    int         distance;



}              t_sprite;

typedef struct  s_cub
{
    t_data data;
    t_data S_texture;
    t_data NO_texture;
    t_data SO_texture;
    t_data f_texture;
    t_data c_texture;
    t_data WE_texture;
    t_data EA_texture;
    int win_w_h[2];
    int f_colors[3];
    int c_colors[3];
    int row;
    int col;
    char **tmp_map;
    char **map;
    char player_view;

}               t_cub;

typedef struct  s_keys
{
    int w;
    int s;
    int d;
    int a;
    int q;
    int left;
    int right;
}               t_keys;

typedef struct s_mlx
{
    void 		*ptr;
	void 		*window;
    double      posX;
    double      posY;
    double      dirX;
    double      dirY;
    double      planeX;
    double      planeY;
    double      cameraX;
    double      rayDirX;
    double      rayDirY;
    int         mapX;
    int         mapY;
    double      sideDistX;
    double      sideDistY;
    double      deltaDistX;
    double      deltaDistY;
    double      perpWallDist;
    double      moveSpeed;
    double      rotSpeed;
    int         stepX;
    int         stepY;
    t_keys      key;
    int         s_count;
}              t_mlx;


typedef struct  s_check
{
    int count_r;
    int count_f;
    int count_c;
    int count_NO;
    int count_SO;
    int count_WE;
    int count_EA;
    int count_S;
}               t_check;


t_cub       cub;
t_mlx       mlx;
t_sprite *sprites;


// from_libft
void    ft_exit(char *s);
t_check *init_check(void);
int		ft_isspace(char *str);
void	ft_putendl_fd(char *s, int fd);
int     ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_length(int num);
int     ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strlcpy(char *dest, char *src, int n);
char	*ft_strdup(const char *s);
// checks 
void	map_validation(t_check *check);
// keys
int key_press(int keycode);
int key_release(int keycode);

// helper_functions

// parsing
void    parsing(char *argv);
char*    get_path(char *line);
void    get_size(char *line, int *color, int n, char c);
void     check_map_name(char *string, char *ext);

char	*ft_strjoin(char *s1, char  *s2);

// split
int		ft_countword(char *s, char c);
int		ft_wordlen(char *s, char c);
char	**ft_free(char **a);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	**ft_split(char const *s, char c);

//mlx_utils
int    ft_close();
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		get_color(t_data *data, int x, int y);
int     rgb(int *colors);
void    set_mlx_images();
void    set_mlx_addresses();

//set_args
void    check_map();
void    set_player_pos(int x, int y);
void    set_player_dir_plane(char **map);

//read_map
void    check_col_border(char *str);
void    check_row_border(char *str, int col);
void     is_star(int i, int j);
void    make_map();

// raycasting
int     game();
void    ft_raycasting();

void init();
void ft_clear();

void read_keys();

// sprites

void make_sprites();

#endif