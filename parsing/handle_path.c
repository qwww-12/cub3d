#include "../cub3d.h"

bool    handle_path_map(char *path)
{
    int     r;

    r = ft_strlen(path) - 4;
    if (!ft_strcmp(path + r, ".cub"))
        return (1);
    return (0);
}
