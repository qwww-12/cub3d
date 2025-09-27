/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarhoun <mbarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:12:54 by mbarhoun          #+#    #+#             */
/*   Updated: 2025/09/27 15:09:00 by mbarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRS_H
# define PRS_H

# include "./get_next_line/gnl.h"

typedef struct s_config 	t_config;
typedef struct s_textures   t_textures;
typedef struct s_rgb        t_rgb;
typedef struct s_file       t_file;

typedef struct  s_file
{
    char    *line;
    t_file  *next;
}   t_file;

typedef struct s_var
{
    bool    flag;
	int     r;
	int     ret;
	int     n;
}   t_var;

/*~~~~~~~~~~~~~~~~~~~~<cub3d_map.c>~~~~~~~~~~~~~~~~~~*/
bool	is_valid_map(t_config *config, char *pmap);
/*~~~~~~~~~~~~~~~~~~~~<utils00.c>~~~~~~~~~~~~~~~~~~*/
int		open_fd(char *file);
void	p_error(const char *s);
/*~~~~~~~~~~~~~~~~~~~~<utils01.c>~~~~~~~~~~~~~~~~~~*/
void	skip_space(int *r, char *str);
void	back_space(int *r, char *str);
bool	is_space(char c);
bool	is_player(char c);
bool	is_normal(char c);
/*~~~~~~~~~~~~~~~~~~~~<utils02.c>~~~~~~~~~~~~~~~~~~*/
bool	just_space(char *line);
bool	is_correct_rgb(int n);
int	    number_of_words(char **split);
void	free_node(t_file **file, int n);
int		real_char_len(char *str);
/*~~~~~~~~~~~~~~~~~~~~<utils03.c>~~~~~~~~~~~~~~~~~~*/
bool	is_all_space(char c);
void	skip_all_space(int *r, char *str);
void    delete_just_sps_head(t_file **file);
void    delete_just_sps_last(t_file *file);
/*~~~~~~~~~~~~~~~~~~~~<valid_map.c>~~~~~~~~~~~~~~~~~~*/
bool	first_line_mp(t_config *config, int p_block, int r);
bool	last_line_mp(t_config *config, int p_block, int r);
bool	check_map_walls(t_config *config, int *p_block, int ln, int player);
/*~~~~~~~~~~~~~~~~~~~~<getc_map.c>~~~~~~~~~~~~~~~~~~*/
char    **get_content_map(t_file *file, int *ln);


t_file  *linked_list(int ln);
bool    handle_path_map(char *path);
bool    void_place(char **map);
bool    is_valid_config(t_config *config, t_file **file);
bool    floor_color(t_config *config, t_file **file);
bool    ceiling_color(t_config *config, t_file **file);
bool    no_texture(t_config *config, t_file **file);
bool    so_texture(t_config *config, t_file **file);
bool    we_texture(t_config *config, t_file **file);
bool    ea_texture(t_config *config, t_file **file);

#endif