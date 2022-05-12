# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 11:03:06 by vrudyka           #+#    #+#              #
#    Updated: 2019/06/25 11:03:08 by vrudyka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=				RTv1

SRC_DIR :=			./src/
OBJ_DIR :=			./obj/
INC_DIR :=			./inc/

SRC :=				main.c\
					parse_scene.c\
					parse_objects.c\
					parse_utils.c\
					parse_utils_iter.c\
					generate_image.c\
					generate_utils.c\
					intersect_objects.c\
					intersect_utils.c\
					light_and_shading.c\
					display_utils.c\
					vector_utils.c\
					update.c\
					controls.c
OBJ =				$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT =				$(LIBFT_DIR)libft.a
LIBFT_DIR :=		$(LIB_DIR)libft/
LIBFT_INC :=		$(LIBFT_DIR)includes/
LIBFT_FLAGS :=		-lft -L $(LIBFT_DIR)

SDL2_INC :=			-I./frameworks/SDL2.framework/Headers

FRAMEWORKS :=		-F./frameworks \
					-rpath ./frameworks \
					-framework SDL2 -framework OpenCL

CC_FLAGS :=			-Wall -Wextra -g #-Wpadded -Werror
LINK_FLAGS :=		$(LIBFT_FLAGS) $(SDL2_FLAGS)
HEADER_FLAGS :=		-I $(INC_DIR)  -I $(LIBFT_INC)

CC :=				gcc

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		@gcc $(CC_FLAGS) $(OBJ) $(LINK_FLAGS) $(FRAMEWORKS) -o $(NAME)
		@printf "$(NAME): $(GREEN)Created $(NAME)\n$(RESET)"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)
		@printf "$(NAME): $(GREEN)Created obj directory\n$(RESET)"
		@printf "$(NAME): $(GREEN)Complining object files...\n$(RESET)"

$(OBJ_DIR)%.o: %.c
		@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS) $(SDL2_INC)

$(LIBFT):
		@make -C $(LIBFT_DIR)
		@printf "$(NAME): $(GREEN)Compiling $(LIBFT)...\n$(RESET)"

clean:
		@rm -f $(OBJ)
		@make clean -C $(LIBFT_DIR)
		@printf "$(NAME): $(RED)Object files deleted\n$(RESET)"
		@printf "$(NAME): $(RED)Libft object files deleted\n$(RESET)"

fclean:
		@rm -f $(NAME)
		@rm -rf $(OBJ_DIR)
		@make fclean -C $(LIBFT_DIR)
		@printf "$(NAME): $(RED)$(NAME) deleted\n$(RESET)"
		@printf "$(NAME): $(RED)Object files deleted\n$(RESET)"
		@printf "$(NAME): $(RED)Libft fclean\n$(RESET)"

re: fclean all

vpath %.c $(SRC_DIR)
