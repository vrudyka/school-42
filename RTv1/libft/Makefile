# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/26 11:54:46 by vrudyka           #+#    #+#              #
#    Updated: 2018/11/16 11:53:36 by vrudyka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CBJ = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	  ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c\
	  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c\
	  ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
	  ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c\
	  ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c\
	  ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c\
	  ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c\
	  ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c\
	  ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c\
	  ft_tolower.c ft_toupper.c ft_lstadd_head.c ft_lstadd_end.c ft_lstdel.c\
	  ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c get_next_line.c\
	  ft_swap.c split_count.c split_free.c ft_atof.c ft_atoi_base.c\
	  ft_fswap.c

INCL = includes

OBJ = $(CBJ:.c=.o)

FLAGS = -Wall -Wextra -g -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o: %.c
	@gcc -I$(INCL) $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
