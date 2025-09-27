/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarhoun <mbarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:01:24 by mbarhoun          #+#    #+#             */
/*   Updated: 2025/09/27 17:01:34 by mbarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	cline_map(int fd)
{
	char	*gnl;
	int		ln;

	ln = 0;
	gnl = get_next_line(fd);
	while (gnl)
	{
		ln++;
		free(gnl);
		gnl = get_next_line(fd);
	}
	return (ln);
}

static void	delete_newline(t_file *file)
{
	char	*tmp;
	char	*lks;
	int		v;

	while (file)
	{
		tmp = file->line;
		lks = file->line;
		file->line = malloc(ft_strlen(tmp));
		if (!file->line)
			p_error(ERR_MEM);
		v = 0;
		while (*tmp)
		{
			if (*tmp != '\n')
				file->line[v++] = *tmp;
			tmp++;
		}
		file->line[v] = '\0';
		free(lks);
		file = file->next;
	}
}

static void	populate_map(t_file *file, int fd, int ln)
{
	int		r;

	r = -1;
	while (++r < ln)
	{
		file->line = get_next_line(fd);
		file = file->next;
	}
}

static bool	check_map_content(t_config *config, int ln)
{
	int	p_block;

	p_block = 1;
	if (!first_line_mp(config, 0, 0))
		return (0);
	if (!check_map_walls(config, &p_block, ln - 2, 0))
		return (0);
	if (!last_line_mp(config, p_block, 0))
		return (0);
	return (1);
}

bool	is_valid_map(t_config *config, char *pmap)
{
	t_file	*file;
	t_file	*tmp;
	int		fd;
	int		ln;
	int		r;

	fd = open_fd(pmap);
	ln = cline_map(fd);
	if (!ln)
		return (p_error("Map not valid\n"), 0);
	file = linked_list(ln);
	close(fd);
	fd = open_fd(pmap);
	populate_map(file, fd, ln);
	close(fd);
	delete_newline(file);
	tmp = file;
	if (!is_valid_config(config, &file))
		return (0);
	delete_just_sps_head(&file);
	delete_just_sps_last(file);
	tmp = file;
	config->map = get_content_map(file, &ln);
	if (!config->map)
		return (0);
	if (!check_map_content(config, ln))
		return (0);
	if (!void_place(config->map))
		return (p_error("Map not valid\n"), 0);
	write_config(pmap);
	return (1);
}
