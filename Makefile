# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/27 17:07:31 by vmercadi          #+#    #+#              #
#    Updated: 2017/10/25 17:16:39 by vmercadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = srcs/wolf.c srcs/event.c srcs/raycasting.c srcs/utils.c srcs/parsing.c

VERSION_GET := $(shell sw_vers | grep "ProductVersion:" | tail -c 8 | head -c 5)
SIERRA = 10.12
EL_CAPITAN = 10.11
MLX_S = autre/minilibx_macos_sierra/
MLX_ = autre/minilibx_macos/
ifeq ($(VERSION_GET), $(SIERRA))
    MLX = $(MLX_S)
else
    MLX = $(MLX_)
endif

CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
MFLAGS = -framework OpenGL -framework AppKit -L $(MLX) -lmlx -lpthread
INCLUDES = -I includes -I $(MLX) -I libft

SRCO = $(SRC:%.c=%.o)

LIB = libft/libft.a

.PHONY: all re cleans

all: $(NAME)

$(NAME):$(SRCO)
	@make -s -C $(MLX)
	@echo "\033[32;4mMLX\x1b[0m	\033[32;7mcompiled\x1b[0m"
	@make -s -C libft/
	@echo "\033[32;4mLIBFT\x1b[0m	\033[32;7mcompiled\x1b[0m"
	@gcc $(CFLAGS) $(LIB) -o $(NAME) $(SRC) $(MFLAGS) $(INCLUDES)
	@echo "\033[32;4mWOLF3D\x1b[0m	\033[32;7mcompiled\x1b[0m"
	@echo "\033[32;3m-----------------------------------"
	@echo "Things went great ! For this time.."
	@echo "-----------------------------------\x1b[0m"

it: all
	@./wolf3d maps/01
clean:
	@rm -rf $(SRCO)
	@make clean -s -C libft/
	@make clean -s -C $(MLX)/

fclean: clean
	@rm -rf $(NAME)
	@make fclean -s -C libft/

re: fclean all

ultra: all clean

reit: re clean
	@./wolf3d maps/01
