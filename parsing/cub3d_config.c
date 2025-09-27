#include "../cub3d.h"

bool    is_valid_config(t_config *config, t_file **file)
{
	if (!floor_color(config, file))
		return (0);
	if (!ceiling_color(config, file))
		return (0);
	config->txt = malloc(sizeof(t_textures));
    if (!config->txt)
        return (p_error(ERR_MEM), 0);
	if (!no_texture(config, file))
		return (0);
	if (!so_texture(config, file))
		return (0);
	if (!we_texture(config, file))
		return (0);
	if (!ea_texture(config, file))
		return (0);
	return (1);
}
