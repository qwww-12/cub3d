#include "../cub3d.h"

static int  check_EA(t_config *config, char *line, int r, bool *flag)
{
	char    **split;

	if (line[r] == 'E' && line[r + 1] == 'A' && is_all_space(line[r + 2]))
	{
		if (*flag == 1)
			return (p_error("Config not valid\n"), 0);
		r += 2;
		skip_all_space(&r, line);
		if (!line[r])
			return (p_error("Config not valid\n"), 0);
        config->txt->ea_texture = ft_strdup(line + r);
        if (!config->txt->ea_texture)
            return (p_error(ERR_MEM), 0);
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
	res = check_EA(config, (*tmp)->line, var->r, &var->flag);
	if (!res)
		return (0);
	else if (res == 2)
	{
		if (count > 1)
			return (p_error("Config not valid\n"), 0);
		*tmp = (*tmp)->next;
		free_node(file, var->n);
		var->n--;
		return (2);
	}
	return (1);
}

bool    ea_texture(t_config *config, t_file **file)
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
