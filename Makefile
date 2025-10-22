# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/14 11:29:40 by brturcio          #+#    #+#              #
#    Updated: 2025/10/22 21:13:30 by yel-mens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= cub3D
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g

DIR_SRCS	:= sources
DIR_OBJS	:= objs
DIR_LIBFT	:= libraries/libft
DIR_MLX		:= libraries/minilibx-linux

SRCS := main.c file.c parse.c error.c init.c header.c image.c map.c list.c flood_fill.c player.c frame.c input.c loop.c draw.c
OBJS := $(SRCS:.c=.o)
OBJS := $(addprefix $(DIR_OBJS)/, $(OBJS))

LIBFT		:= $(DIR_LIBFT)/libft.a
MLX_LIB		:= $(DIR_MLX)/libmlx.a

INCLUDES	:= -I$(DIR_LIBFT)/inc -I$(DIR_MLX) -Iincludes

MLX_FLAGS	:= -L$(DIR_MLX) -lmlx -lXext -lX11 -lm -lz

all : $(LIBFT) $(MLX_LIB) $(NAME)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $@
	@echo "✅ Compilation completed: $(NAME)"

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
	@$(MAKE) -s -C $(DIR_LIBFT) fclean
	@echo "✅ fclean done."

re : fclean all

norm	:
	@norminette includes/
	@norminette $(SRCS)

.PHONY : all clean fclean re  norm


