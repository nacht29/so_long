#include "../../includes/so_long.h"

int main(void)
{
    void *mlx;
 
    mlx = mlx_init();
    if (!mlx)
    {
        return (1);
    }
    mlx_destroy_display(mlx);
    free(mlx);
    return (0);
}
