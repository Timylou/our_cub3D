# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 20:21:32 by brturcio          #+#    #+#              #
#    Updated: 2025/05/02 22:32:04 by yel-mens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror -g -Iinc

OBJDIR		:= obj
SRCDIRS		:= libft ft_printf get_next_line
SRC		:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))
OBJ		:= $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@echo "✅ Library created : $(NAME)"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	# @echo "✅ clean libft done."

fclean: clean
	@rm -f $(NAME)
	# @echo "✅ fclean libft done."

re: fclean all

.PHONY: all clean fclean re
