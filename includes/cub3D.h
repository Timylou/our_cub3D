/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:01:30 by brturcio          #+#    #+#             */
/*   Updated: 2025/10/17 15:10:55 by yel-mens         ###   ########.fr       */
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

/* * * * * *
*  structs *
* * * * * **/

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

typedef struct  s_game
{
    void    *mlx;
    void    *win;
    int     width;
    int     height;
	int		floor_color;
	int		ceiling_color;
	t_img	*NO_img;
	t_img	*SO_img;
	t_img	*WE_img;
	t_img	*EA_img;
}               t_game;

/* * * * *
* init *
* * * * **/
t_game  *ft_init_game(void);

/* * * * * *
* parsing *
* * * * * **/
t_game  *ft_parse(char *map_name);
int     ft_open_file(char *filename, char *suffix, t_game *game);
void    ft_open_header(int fd, t_game *game);

/* * * * * * 
*  image *
* * * * * **/
int		ft_get_pixel(t_img *img, int x, int y);
void	ft_put_pixel(t_img *img, int x, int y, int color);
void	ft_put_image(t_img *img, int x_offset, int y_offset, t_img *buffer);
t_img	*ft_open_image(void *mlx, char *name, int width, int height);


/* * * * * * * * * 
* errors/free *
* * * * * * * * **/
void    ft_error(char *msg, t_game *game);
void    ft_free_all(t_game *game);
void	ft_free_split_gnl(char *msg, char **split_line, int fd, t_game *game);
void	ft_free_split(char **split_line);
void	ft_free_image(t_img *img, t_game *game);

#endif
