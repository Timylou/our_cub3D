/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_struct_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:59:04 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/10 14:56:17 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_BONUS_H
# define CUB3D_STRUCT_BONUS_H

# include "libft.h"

typedef enum e_direction
{
	UP,
	DOWN,
	RIGHT,
	LEFT
}			t_direction;

typedef struct s_img	t_img;
typedef struct s_game	t_game;

typedef struct s_sprite
{
	double		x;
	double		y;
	double		dist;
	int			anim_frame;
	long long	last_anim_time;

}	t_sprite;

typedef struct s_sprite_draw
{
	t_game		*game;
	t_img		*texture;
	double		transform_x;
	double		transform_y;
	int			screen_x;
	int			height;
	int			width;
	int			start_x;
	int			end_x;
	int			start_y;
	int			end_y;
}	t_sprite_draw;

typedef struct s_minimap_data
{
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;
	int		player_screen_x;
	int		player_screen_y;
	t_game	*game;
}	t_minimap_data;

typedef struct s_info
{
	t_img	*tex;

	int		t_width;
	int		t_height;
	int		tex_y;
	int		tex_x;
	int		color;
	int		screen_y;
	double	step;
	double	t_pos;
}	t_info;

typedef struct s_ray
{
	double	camara;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	int		side;
	int		hit;
	double	perp_dist;
	double	wall_x;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct t_player
{
	float	x;
	float	y;
	float	angle;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		key_up;
	int		key_down;
	int		key_left;
	int		key_right;
	int		left_rotate;
	int		right_rotate;
	int		key_action;
	int		can_interact;
}				t_player;

typedef struct s_img
{
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		edn;
	int		width;
	int		height;
	int		x;
	int		y;
}				t_img;

typedef struct s_door
{
	int		state;
	int		x;
	int		y;
}	t_door;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			w_width;
	int			w_height;
	char		**map;
	int			m_width;
	int			m_height;
	int			floor_color;
	int			ceiling_color;
	int			count_doors;
	t_img		*no_img;
	t_img		*so_img;
	t_img		*we_img;
	t_img		*ea_img;
	t_img		*door_img;
	t_img		*sprite_1;
	t_img		*sprite_2;
	t_img		*sprite_3;
	t_img		*sprite_4;
	t_player	*player;
	t_img		*frame;
	t_list		*doors;
	t_list		*sprites;
	double		*z_buffer;
}				t_game;

#endif
