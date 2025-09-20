#include "../cub3d.h"

bool    is_valid_config(t_config *config, t_file **file)
{
	if (!floor_color(config, file) || !ceiling_color(config, file))
		return (0);
	config->txt = malloc(sizeof(t_textures));
    if (!config->txt)
        return (p_error(ERR_MEM), 0);
	if (!no_texture(config, file) || !so_texture(config, file)
		|| !we_texture(config, file) || !ea_texture(config, file))
		return (0);
	return (1);
}
