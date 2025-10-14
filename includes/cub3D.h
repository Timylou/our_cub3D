/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:01:30 by brturcio          #+#    #+#             */
/*   Updated: 2025/10/14 13:11:46 by brturcio         ###   ########.fr       */
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
typedef struct  s_game
{
    void    *mlx;
    void    *win;
    int     width;
    int     height;
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

/* * * * * * * * * 
* errors/free *
* * * * * * * * **/
void    ft_error(char *msg, t_game *game);
void    ft_free_all(t_game *game);

#endif
