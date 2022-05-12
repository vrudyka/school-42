NAME :=				fdf

SRC_DIR :=			./src/
OBJ_DIR :=			./obj/
INC_DIR :=			./inc/

SRC :=				main.c\
					init.c\
					parsing.c\
					bresenham.c\
					keys.c\
					projection.c\
					palette.c\
					utils.c
OBJ =				$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT =				$(LIBFT_DIR)libft.a
LIBFT_DIR :=		$(LIB_DIR)libft/
LIBFT_INC :=		$(LIBFT_DIR)includes/
LIBFT_FLAGS :=		-lft -L $(LIBFT_DIR)

MLX :=				$(MLX_DIR)libmlx.a
MLX_DIR :=			./minilibx_macos/
MLX_INC :=			$(MLX_DIR)
MLX_FLAGS :=		-lmlx -L $(MLX_DIR)

FRAMEWORKS :=		-framework OpenGL -framework AppKit

CC_FLAGS :=			-Wall -Wextra -Werror
LINK_FLAGS :=		$(MLX_FLAGS) $(LIBFT_FLAGS)
HEADER_FLAGS :=		-I $(INC_DIR)  -I $(LIBFT_INC) -I $(MLX_INC)

CC :=				gcc

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
		@gcc $(OBJ) $(LINK_FLAGS) $(FRAMEWORKS) -o $(NAME)
		@printf "$(NAME): $(GREEN)Created $(NAME)\n$(RESET)"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)
		@printf "$(NAME): $(GREEN)Created obj directory\n$(RESET)"
		@printf "$(NAME): $(GREEN)Complining object files...\n$(RESET)"

$(OBJ_DIR)%.o: %.c
		@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
		@make -C $(LIBFT_DIR)
		@printf "$(NAME): $(GREEN)Compiling $(LIBFT)...\n$(RESET)"

$(MLX):
		@$(MAKE) -sC $(MLX_DIR)
		@printf "$(NAME): $(GREEN)Compiling $(MLX)...\n$(RESET)"

clean:
		@rm -f $(OBJ)
		@make clean -C $(LIBFT_DIR)
		@printf "$(NAME): $(RED)Object files deleted\n$(RESET)"
		@printf "$(NAME): $(RED)Libft object files deleted\n$(RESET)"

fclean: clean
		@rm -f $(NAME)
		@rm -rf $(OBJ_DIR)
		@make fclean -C $(LIBFT_DIR)
		@printf "$(NAME): $(RED)$(NAME) deleted\n$(RESET)"
		@printf "$(NAME): $(RED)Object files deleted\n$(RESET)"
		@printf "$(NAME): $(RED)Libft fclean\n$(RESET)"

re: fclean all

vpath %.c $(SRC_DIR)
