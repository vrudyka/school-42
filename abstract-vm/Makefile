NAME :=		avm

SRC :=		src/main.cpp\
			src/AbstractVM.cpp\
			src/Factory.cpp\
			src/Lexer.cpp\
			src/Parser.cpp\
			src/Error.cpp
OBJ :=		$(patsubst src/%.cpp,obj/%.o,$(SRC))

FLAG :=		-Wall -Wextra -Werror
INC :=		-Iinc
CC :=		clang++ -std=c++11

GREEN :=	\033[0;32m
RED :=		\033[0;31m
RESET :=	\033[0m

.SILENT:

all: $(NAME)

$(NAME): linking $(OBJ)
	$(CC) $(FLAG) $(SRC) -o $(NAME) $(INC)
	@printf "\n$(NAME): $(GREEN)Created $(NAME)\n$(RESET)"

linking:
	@printf "$(NAME): $(RESET)"

obj/%.o: src/%.cpp
	mkdir -p obj
	$(CC) $(FLAG) -c $< -o $@ $(INC)
	@printf "$(GREEN).$(RESET)"

clean:
	/bin/rm -rf obj/
	@printf "$(NAME): $(RED)Object files deleted\n$(RESET)"

fclean: clean
	/bin/rm -f $(NAME)
	@printf "$(NAME): $(RED)$(NAME) deleted\n$(RESET)"

re: fclean all
