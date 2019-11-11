# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 16:03:44 by jmoucach          #+#    #+#              #
#    Updated: 2019/11/11 17:56:15 by jmoucach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################################################################
#								Colors										   #
################################################################################

RED= \033[31m
WHITE= \033[0m
GREEN= \033[32m
CYAN= \033[36m
BLUE= \033[34m
YELLOW= \033[33m
MAGENTA= \033[35m

################################################################################
#								Macros										   #
################################################################################
NAME= Wolf3d
CC= gcc
CFLAGS= -Wall -Wextra -Werror -g `sdl2-config --cflags` 
SRC_DIR= src/
SRC= init/main.c\
	 init/init.c\
	 draw/drawline.c\
	 draw/draw_rect_to_sdl.c\
	 draw/draw_minimap.c\
	 draw/show_player.c\
	 map/new_map.c\
	 map/fill_map.c\
	 map/parsing.c\
	 raycasting/raycasting.c\
	 raycasting/floorcaster.c\
	 game/event_loop.c\
	 game/movement.c\
	 image/load_image.c
SRCS= $(addprefix $(SRC_DIR),$(SRC))
OBJ_DIR= obj/
OBJ= $(SRC:.c=.o)
OBJ_SUBDIRS= init draw map raycasting game  image
OBJS= $(addprefix $(OBJ_DIR), $(OBJ))
SUBDIRS= $(foreach dir, $(OBJ_SUBDIRS), $(OBJ_DIR)$(dir))
LIB= `sdl2-config --libs` \
	 -L libft -lft
LIBFT= libft.a
INCLUDES=	hdr/wolf3d.h\
			hdr/proto.h\
			hdr/struct.h

###############################################################################
#								Rules										  #
###############################################################################

all: $(SUBDIRS) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@ echo "$(YELLOW)Creating $@ executable$(WHITE)"
	@ $(CC) -o $@ $(CFLAGS) $(OBJS) $(LIB) $(FRAMEWORK)
	@echo "$(GREEN)$@ executable created$(WHITE)"

$(LIBFT): FORCE
	@ make -C libft 1>/dev/null

$(SUBDIRS):
	@ mkdir -p $(SUBDIRS)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(INCLUDES) Makefile
	@ $(CC) -o $@ -c $< $(CFLAGS) $(SDL2_CFLAGS)
	@ echo "$(GREEN)[✔]$(WHITE)$@"

clean:
	@ echo "$(YELLOW)Deleting objects$(WHITE)"
	@ for i in $(OBJ); do \
		echo "$(RED)- Deleting $$i$(WHITE)"; \
	done;
	@ echo "$(GREEN)Objects deleted$(WHITE)"
	@ rm -rf $(OBJS)

fclean: clean
	@ echo "$(BLUE)Cleaning libft$(WHITE)"
	@ make -C libft fclean
	@ echo "$(YELLOW)Deleting obj directory$(WHITE)"
	@ rm -rf obj
	@ echo "$(GREEN)Obj directory deleted$(WHITE)"
	@ echo "$(GREEN)Executable deleted$(WHITE)"
	@ rm -rf $(NAME)

instalSDL:
	brew install SDL2

re: fclean all

FORCE:

.PHONY: all re fclean clean
