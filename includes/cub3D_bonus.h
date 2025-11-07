/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:15:04 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/07 13:14:16 by brturcio         ###   ########.fr       */
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

# define FRAME_TIME (1000000 / 60)
# define PI 3.14159265359
# define BLOCK 10
# define FOV_PLANE 0.66
# define STATE_CLOSED 0
# define STATE_OPEN 1
# define MINIMAP_SIZE 180
# define MINIMAP_OFFSET 20

typedef enum e_direction
{
	UP,
	DOWN,
	RIGHT,
	LEFT
}			t_direction;

typedef struct s_img	t_img;
typedef struct s_game	t_game;

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
	t_ray		*ray;
	t_info		*info;
	t_list		*doors;
}				t_game;

void	ft_door_status_check(t_game *game);
void	ft_is_door(t_game *game, int x, int y);
void	ft_validate_door(t_game *game);
t_door	*ft_get_door(t_game *game, int x, int y);
int		ft_check_wall_door(t_game *game, t_ray *r);
t_game	*ft_init_game(void);
t_game	*ft_parse(char *map_name);
int		ft_open_file(char *filename, char *suffix, t_game *game);
int		ft_check_id_continue(char *id);
int		ft_switch_img2(char *id, t_img *img, t_game *game);
int		ft_open_header(int fd, t_game *game);
void	ft_open_map(int fd, t_game *game);
void	ft_handle_lst(t_list *lst, int width, int height, t_game *game);
void	ft_flood_fill(t_game *game);
int		ft_get_pixel(t_img *img, int x, int y);
void	ft_put_pixel(t_img *img, int x, int y, int color);
void	ft_put_image(t_img *img, int x_offset, int y_offset, t_img *frame);
t_img	*ft_open_image(void *mlx, char *name, int width, int height);
void	ft_clear_frame(t_game *game);
int		ft_handle_input(int keysym, t_game *game);
int		ft_handle_release(int keysym, t_game *game);
void	ft_check_movement_continue(t_player *p, float ex_x, float ex_y, \
t_game *g);
void	ft_move_player(t_player *player, t_game *game);
void	ft_draw_square(int x, int y, int size, t_game *game);
void	ft_draw_player(float x, float y, int size, t_game *game);
void	ft_draw_map(t_game *game);
void	ft_draw_line(t_player *player, float start_x, int i, t_game *game);
int		ft_loop(t_game *game);
void	ft_error(char *msg, t_game *game);
void	ft_free_all(t_game *game);
void	ft_free_split_gnl(char *msg, char **split_line, int fd, t_game *game);
void	ft_free_split(char **split_line);
void	ft_free_image(t_img *img, t_game *game);
void	ft_free_map(t_game *game);
void	ft_free_gnl_error(char *msg, int fd, t_game *game);
void	ft_free_doors(t_game *game);
double	my_abs(double n);
void	ft_realistic_height(t_game *game, t_ray *r);
void	ft_draw_texture(t_game *game, t_ray *r, int i);
void	ft_raycast(t_game *game);
int		ft_get_time(void);
void	ft_put_pixel_minimap(t_img *img, int x, int y, int color);
void	ft_draw_minimap_background(t_game *game);
int		ft_is_wall_or_door(t_game *game, float ray_x, float ray_y);

#endif
