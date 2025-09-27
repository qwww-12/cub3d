#include "../cub3d.h"

static bool set_rgb_floor(t_config *config, char **split)
{
    config->ceiling_color = malloc(sizeof(t_rgb));
    if (!config->ceiling_color)
        return (p_error(ERR_MEM), 0);
    config->ceiling_color->red = ft_atoi(split[0]);
    config->ceiling_color->green = ft_atoi(split[1]);
    config->ceiling_color->blue = ft_atoi(split[2]);
    if (!is_correct_rgb(config->ceiling_color->red) ||
        !is_correct_rgb(config->ceiling_color->green) ||
        !is_correct_rgb(config->ceiling_color->blue))
        return (p_error("Config not valid\n"), 0);
    return (1);
}

static int  check_C(t_config *config, char *line, int r, bool *flag)
{
    char    **split;

    if (line[r] == 'C' && is_all_space(line[r + 1]))
    {
        if (*flag == 1)
            return (p_error("Config not valid\n"), 0);
        r++;
        skip_all_space(&r, line);
        if (!line[r])
            return (p_error("Config not valid\n"), 0);
        split = ft_split(line + r, ',');
        if (number_of_words(split) != 3 || !set_rgb_floor(config, split))
            return (0);
        *flag = 1;
        return (2);
    }
    return (1);
}

static int	check_result(t_config *config, t_var *var, t_file **file, t_file **tmp)
{
	static int	count;
	int			res;

	if (real_char_len((*tmp)->line) > 1)
		count++;
	res = check_C(config, (*tmp)->line, var->r, &var->flag);
	if (!res)
		return (0);
	else if (res == 2)
	{
		if (count > 5)
			return (p_error("Config not valid\n"), 0);
		*tmp = (*tmp)->next;
		free_node(file, var->n);
		var->n--;
		return (2);
	}
	return (1);
}

bool    ceiling_color(t_config *config, t_file **file)
{
	t_var	var;
	t_file	*tmp;

	var.flag = 0;
	var.n = -1;
	tmp = *file;
	while (tmp && ++var.n != -2)
	{
		var.r = 0;
		skip_all_space(&var.r, tmp->line);
		if (!tmp->line[var.r])
		{
			tmp = tmp->next;
			continue ;
		}
		var.ret = check_result(config, &var, file, &tmp);
		if (var.ret == 0)
			return (0);
		else if (var.ret == 2)
			continue ;
		tmp = tmp->next;
	}
	if (!var.flag)
		return (p_error("Config not valid\n"), 0);
	return (1);
}
