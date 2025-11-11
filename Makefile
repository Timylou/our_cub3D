# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/14 11:29:40 by brturcio          #+#    #+#              #
#    Updated: 2025/11/11 14:18:26 by brturcio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			:= cub3D
NAME_BONUS		:= cub3D_bonus
CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -g

DIR_BONUS_SRCS	:= sources/bonus
DIR_SRCS		:= sources/mandatory
DIR_OBJS		:= objs
DIR_LIBFT		:= libraries/libft
DIR_MLX			:= libraries/minilibx-linux

SRCS :=			main.c file.c parse.c error.c init.c header.c \
				image.c map.c list.c flood_fill.c player.c \
				frame.c input.c loop.c raycasting.c \
				draw_texture.c proyection.c

BONUS_SRCS :=	door_bonus.c draw_bonus.c draw_utils_bonus.c error_bonus.c error_utils_bonus.c \
				file_bonus.c flood_fill_bonus.c frame_bonus.c header_bonus.c header_utils_bonus.c \
				image_bonus.c init_bonus.c input_bonus.c list_bonus.c loop_bonus.c main_bonus.c \
				map_bonus.c minimap_bonus.c mouse_bonus.c parse_bonus.c player_bonus.c \
				proyection_bonus.c raycasting_bonus.c sprites_bonus.c sprites_draw_bonus.c \
				sprites_utils_bonus.c time_bonus.c

OBJS :=			$(SRCS:.c=.o)
OBJS :=			$(addprefix $(DIR_OBJS)/, $(OBJS))

BONUS_OBJS :=	$(BONUS_SRCS:.c=.o)
BONUS_OBJS :=	$(addprefix $(DIR_OBJS)/, $(BONUS_OBJS))

LIBFT			:= $(DIR_LIBFT)/libft.a
MLX_LIB			:= $(DIR_MLX)/libmlx.a

INCLUDES		:= -I$(DIR_LIBFT)/inc -I$(DIR_MLX) -Iincludes

MLX_FLAGS		:= -L$(DIR_MLX) -lmlx -lXext -lX11 -lm -lz

all : $(LIBFT) $(MLX_LIB) $(NAME)

bonus : $(LIBFT) $(MLX_LIB) $(NAME_BONUS)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(DIR_OBJS)/%_bonus.o: $(DIR_BONUS_SRCS)/%_bonus.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $@
	@echo "✅ Compilation completed: $(NAME)"

$(NAME_BONUS): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MLX_FLAGS) -o $@
	@echo "✅ Compilation completed: $(NAME_BONUS)"

$(LIBFT):
	@if [ ! -f $@ ] ; then \
		$(MAKE) -s -C $(DIR_LIBFT); \
	fi

$(MLX_LIB):
	@if [ ! -f $@ ]; then \
		$(MAKE) -s -C $(DIR_MLX) > /dev/null 2>&1; \
		echo "✅ Library created : MLX"; \
	fi

clean :
	@rm -rf $(DIR_OBJS)
	@$(MAKE) -s -C $(DIR_LIBFT) clean
	@$(MAKE) -s -C $(DIR_MLX) clean >/dev/null 2>&1 || true
	@echo "✅ clean done."

fclean : clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@$(MAKE) -s -C $(DIR_LIBFT) fclean
	@echo "✅ fclean done."

re : fclean all

rebonus : fclean bonus

norm :
	@norminette includes
	@norminette $(DIR_SRCS)
	@norminette $(DIR_BONUS_SRCS)

.PHONY : all clean fclean re rebonus norm bonus


