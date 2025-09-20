/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarhoun <mbarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:18:06 by mbarhoun          #+#    #+#             */
/*   Updated: 2025/06/27 18:32:53 by mbarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "./libft/libft.h"
# include "./parsing/parsing.h"

# define ERR_MEM "Allocation Faield\n"

typedef struct s_rgb
{
	int		red;
	int		green;
	int		blue;
}	t_rgb;

typedef struct	s_textures
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
}	t_textures;

typedef struct s_config
{
	char		**map;
	t_textures	*txt;
	t_rgb		*floor_color;
	t_rgb		*ceiling_color;
	int			pos_x;
	int			pos_y;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
}	t_config;

#endif