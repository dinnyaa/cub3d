#include "cub3d.h"

t_check *init_check(void)
{
    t_check *check;

    if (!(check = (t_check*)malloc(sizeof(t_check))))
        ft_exit("Malloc Error");
    check->count_c = 0;
    check->count_f = 0;
    check->count_r = 0;
    check->count_EA = 0;
    check->count_S = 0;
    check->count_SO = 0;
    check->count_WE = 0;
    check->count_NO = 0;
    
    return (check);
}

void	map_validation(t_check *check)
{
	if (check->count_r != 1 || check->count_f != 1 || check->count_c != 1 || check->count_NO != 1
    || check->count_SO != 1 || check->count_S != 1 || check->count_EA != 1 || check->count_WE != 1)
    {   
        free(check);
        ft_exit("Error Map");
    }
	free(check);
}