/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:15:04 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/12 12:07:35 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "mlx.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"

# define FRAME_TIME 16666
# define PI 3.14159265359
# define BLOCK 10
# define FOV_PLANE 0.66
# define STATE_CLOSED 0
# define STATE_OPEN 1
# define MINIMAP_SIZE 180
# define MINIMAP_OFFSET 20
# define ANIM_SPEED 100000
# define TRANSPARENCY_COLOR 0x0
# define MOUSE_SENSITIVITY 0.002
# define ANGLE_SPEED 0.05
# define SPEED 0.04

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

/* [ door_bonus.c ] ══════════════════════════════════════════════════════════*/
void		ft_door_status_check(t_game *game);
t_door		*ft_get_door(t_game *game, int x, int y);
void		ft_is_door(t_game *game, int x, int y);
void		ft_validate_door(t_game *game);

/* [ draw_bonus.c ] ══════════════════════════════════════════════════════════*/
void		ft_draw_player(float x, float y, int size, t_game *game);
void		ft_draw_line(t_player *player, float start_x, int i, t_game *game);
void		ft_draw_map(t_game *game);

/* [ draw_texture_bonus.c ] ══════════════════════════════════════════════════*/
void		ft_draw_texture(t_game *game, t_ray *r, int i);

/* [ error_bonus.c ] ═════════════════════════════════════════════════════════*/
void		ft_free_all(t_game *game);
void		ft_error(char *msg, t_game *game);

/* [ error_utils_bonus.c ] ═══════════════════════════════════════════════════*/
void		ft_free_doors(t_game *game);
void		ft_free_sprites(t_game *game);

/* [ file_bonus.c ] ══════════════════════════════════════════════════════════*/
int			ft_open_file(char *filename, char *suffix, t_game *game);

/* [ flood_fill_bonus.c ] ════════════════════════════════════════════════════*/
void		ft_flood_fill(t_game *game);

/* [ frame_bonus.c ] ═════════════════════════════════════════════════════════*/
void		ft_clear_frame(t_game *game);

/* [ header_bonus.c ] ════════════════════════════════════════════════════════*/
int			ft_open_header(int fd, t_game *game);

/* [ header_utils_bonus.c ] ══════════════════════════════════════════════════*/
int			ft_check_id_02(char *id);
int			ft_switch_img_02(char *id, t_img *img, t_game *game);

/* [ image_bonus.c ] ═════════════════════════════════════════════════════════*/
void		ft_free_image(t_img *img, t_game *game);
int			ft_get_pixel(t_img *img, int x, int y);
void		ft_put_pixel(t_img *img, int x, int y, int color);
t_img		*ft_open_image(void *mlx, char *name, int width, int height);

/* [ init_bonus.c ] ══════════════════════════════════════════════════════════*/
t_game		*ft_init_game(void);

/* [ input_bonus.c ] ═════════════════════════════════════════════════════════*/
int			ft_handle_input(int keysym, t_game *game);
int			ft_handle_release(int keysym, t_game *game);

/* [ list_bonus.c ] ══════════════════════════════════════════════════════════*/
void		ft_handle_lst(t_list *lst, int width, int height, t_game *game);

/* [ loop_bonus.c ] ══════════════════════════════════════════════════════════*/
int			ft_loop(t_game *game);

/* [ map_bonus.c ] ═══════════════════════════════════════════════════════════*/
void		ft_open_map(int fd, t_game *game);
void		ft_free_map(t_game *game);

/* [ minimap_bonus.c ] ═══════════════════════════════════════════════════════*/
void		ft_put_pixel_minimap(t_img *img, int x, int y, int color);
void		ft_draw_minimap_background(t_game *game);
int			ft_is_wall_or_door(t_game *game, float ray_x, float ray_y);
void		ft_draw_square(int x, int y, int size, t_game *game);

/* [ mouse_bonus.c ] ═════════════════════════════════════════════════════════*/
int			handle_mouse_move(int x, int y, t_game *game);

/* [ parse_bonus.c ] ═════════════════════════════════════════════════════════*/
void		ft_free_split(char **split_line);
void		ft_free_split_gnl(char *msg, char **split_line, int fd, \
t_game *game);
void		ft_free_gnl_error(char *msg, int fd, t_game *game);
t_game		*ft_parse(char *map_name);

/* [ player_bonus.c ] ════════════════════════════════════════════════════════*/
void		ft_move_player(t_player *player, t_game *game);

/* [ proyection_bonus.c ] ════════════════════════════════════════════════════*/
double		my_abs(double n);
int			ft_check_wall_door(t_game *game, t_ray *r);
void		ft_realistic_height(t_game *game, t_ray *r);

/* [ raycasting_bonus.c ] ════════════════════════════════════════════════════*/
void		ft_raycast(t_game *game);

/* [ sprites_bonus.c ] ═══════════════════════════════════════════════════════*/
void		ft_render_sprites(t_game *game);

/* [ sprites_draw_bonus.c ] ══════════════════════════════════════════════════*/
void		ft_draw_sprite_stripe(t_sprite_draw *d, int x);

/* [ sprites_utils_bonus.c ] ═════════════════════════════════════════════════*/
void		ft_init_sprite(t_game *game, int x, int y);
void		ft_update_sprite_animation(t_sprite *sprite);
void		ft_sort_sprites(t_game *game);

/* [ time_bonus.c ] ══════════════════════════════════════════════════════════*/
long long	get_time_in_usec(void);
int			ft_get_time(void);

#endif
