/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:15:04 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/08 19:41:52 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3D_struct_bonus.h"
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
# define ANIM_SPEED 150000
# define TRANSPARENCY_COLOR 0x0

void		ft_door_status_check(t_game *game);
void		ft_is_door(t_game *game, int x, int y);
void		ft_validate_door(t_game *game);
t_door		*ft_get_door(t_game *game, int x, int y);
int			ft_check_wall_door(t_game *game, t_ray *r);
t_game		*ft_init_game(void);
t_game		*ft_parse(char *map_name);
int			ft_open_file(char *filename, char *suffix, t_game *game);
int			ft_check_id_continue(char *id);
int			ft_switch_img2(char *id, t_img *img, t_game *game);
int			ft_open_header(int fd, t_game *game);
void		ft_open_map(int fd, t_game *game);
void		ft_handle_lst(t_list *lst, int width, int height, t_game *game);
void		ft_flood_fill(t_game *game);
int			ft_get_pixel(t_img *img, int x, int y);
void		ft_put_pixel(t_img *img, int x, int y, int color);
void		ft_put_image(t_img *img, int x_offset, int y_offset, t_img *frame);
t_img		*ft_open_image(void *mlx, char *name, int width, int height);
void		ft_clear_frame(t_game *game);
int			ft_handle_input(int keysym, t_game *game);
int			ft_handle_release(int keysym, t_game *game);
void		ft_check_movement_continue(t_player *p, float ex_x, float ex_y, \
t_game *g);
void		ft_move_player(t_player *player, t_game *game);
void		ft_draw_square(int x, int y, int size, t_game *game);
void		ft_draw_player(float x, float y, int size, t_game *game);
void		ft_draw_map(t_game *game);
void		ft_draw_line(t_player *player, float start_x, int i, t_game *game);
int			ft_loop(t_game *game);
void		ft_error(char *msg, t_game *game);
void		ft_free_all(t_game *game);
void		ft_free_split_gnl(char *msg, char **split_line, int fd, \
t_game *game);
void		ft_free_split(char **split_line);
void		ft_free_image(t_img *img, t_game *game);
void		ft_free_map(t_game *game);
void		ft_free_gnl_error(char *msg, int fd, t_game *game);
void		ft_free_doors(t_game *game);
double		my_abs(double n);
void		ft_realistic_height(t_game *game, t_ray *r);
void		ft_draw_texture(t_game *game, t_ray *r, int i);
void		ft_raycast(t_game *game);
int			ft_get_time(void);
void		ft_put_pixel_minimap(t_img *img, int x, int y, int color);
void		ft_draw_minimap_background(t_game *game);
int			ft_is_wall_or_door(t_game *game, float ray_x, float ray_y);
void		ft_init_sprite(t_game *game, int x, int y);
void		ft_free_sprites(t_game *game);
long long	get_time_in_usec(void);
void		ft_update_sprite_animation(t_sprite *sprite);
int			ft_compare_sprite_dist(void *a, void *b);
void		ft_sort_sprites(t_game *game);
void		ft_render_sprites(t_game *game);
void		ft_lstsort(t_list **list, int (*cmp)(void *, void *));

#endif
