# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/14 11:29:40 by brturcio          #+#    #+#              #
#    Updated: 2025/10/14 12:35:32 by brturcio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= cube3D
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g

DIR_SRCS	:= sources
DIR_OBJS	:= objs
DIR_LIBFT	:= libraries/libft
DIR_MLX42	:= libraries/MLX42

SRCS		:= $(DIR_SRCS)/main.c

OBJS		:= $(DIR_OBJS)/main.o


LIBFT		:= $(DIR_LIBFT)/libft.a
MLX42_LIB	:= $(MLX42_DIR)/build/libmlx42.a

INCLUDES	:= -I$(DIR_LIBFT)/inc -I$(DIR_MLX42)/include -Iincludes

MLX_FLAGS	:= -ldl -lglfw -lm -lX11 -pthread

all : $(LIBFT) $(MLX42_LIB) $(NAME)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@
	@echo "✅ Compilation completed: $(NAME)"

$(LIBFT):
	@if [ ! -f $@ ] ; then \
		$(MAKE) -s -C $(DIR_LIBFT); \
	fi

$(MLX42_LIB):
	@if [ ! -f $@ ]; then \
		cmake -B $(MLX42_DIR)/build -S $(MLX42_DIR) > /dev/null 2>&1 && \
		$(MAKE) -s -C $(MLX42_DIR)/build -j4 > /dev/null 2>&1; \
		echo "✅ Library created : MLX42";\
	fi

clean :
	@rm -rf $(DIR_OBJS)
	@$(MAKE) -s -C $(DIR_LIBFT) clean
	@echo "✅ clean done."

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -s -C $(DIR_LIBFT) fclean
	@echo "✅ fclean done."

re : fclean all

norm	:
	@norminette include/
	@norminette $(SRCS)

.PHONY : all clean fclean re libft mlx
