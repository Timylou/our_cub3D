/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:01:30 by brturcio          #+#    #+#             */
/*   Updated: 2025/10/22 22:40:18 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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

# define PI 3.14159265359
# define BLOCK 10

/* * * * * *
*  structs *
* * * * * **/

typedef enum e_direction
{
	UP,
	DOWN,
	RIGHT,
	LEFT
}			t_direction;

typedef struct t_player
{
	float	x;
	float	y;
	float	angle;

	int		key_up;
	int		key_down;
	int		key_left;
	int		key_right;

	int		left_rotate;
	int		right_rotate;
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
	t_img		*no_img;
	t_img		*so_img;
	t_img		*we_img;
	t_img		*ea_img;
	t_player	*player;
	t_img		*frame;
}				t_game;

/* * * * *
* init *
* * * * **/
t_game	*ft_init_game(void);

/* * * * * *
* parsing *
* * * * * **/
t_game	*ft_parse(char *map_name);
int		ft_open_file(char *filename, char *suffix, t_game *game);
int		ft_open_header(int fd, t_game *game);
void	ft_open_map(int fd, t_game *game);
void	ft_handle_lst(t_list *lst, int width, int height, t_game *game);
void	ft_flood_fill(t_game *game);

/* * * * * * 
*  image *
* * * * * **/
int		ft_get_pixel(t_img *img, int x, int y);
void	ft_put_pixel(t_img *img, int x, int y, int color);
void	ft_put_image(t_img *img, int x_offset, int y_offset, t_img *frame);
t_img	*ft_open_image(void *mlx, char *name, int width, int height);
void	ft_clear_frame(t_game *game);

/* * * * * *
* input *
* * * * * **/
int		ft_handle_input(int keysym, t_game *game);
int		ft_handle_release(int keysym, t_game *game);

/* * * * * * 
* player *
* * * * * **/
void	ft_move_player(t_player *player, t_game *game);

/* * * * *
* draw *
* * * * **/
void	ft_draw_square(int x, int y, int size, t_game *game);
void	ft_draw_player(int x, int y, int size, t_game *game);
void	ft_draw_map(t_game *game);

/* * * * * 
* loop *
* * * * **/
int		ft_loop(t_game *game);

/* * * * * * * * * 
* errors/free *
* * * * * * * * **/
void	ft_error(char *msg, t_game *game);
void	ft_free_all(t_game *game);
void	ft_free_split_gnl(char *msg, char **split_line, int fd, t_game *game);
void	ft_free_split(char **split_line);
void	ft_free_image(t_img *img, t_game *game);
void	ft_free_map(t_game *game);
void	ft_free_gnl_error(char *msg, int fd, t_game *game);
void	ft_free_player(t_game *game);

#endif
