# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 13:01:16 by alde-abre         #+#    #+#              #
#    Updated: 2025/01/15 18:19:17 by alde-abr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

SRC = \
	ft_printf.c ft_parseformat.c ft_pfbuildchar.c ft_pfbuildhexa.c \
	ft_pfbuildnb.c ft_pfbuildptr.c ft_pfbuildstr.c ft_unslngconvert_base.c \
	ft_pfbuildunsnb.c ft_unslngatoi_base.c ft_unslngconvert_base.c ft_unslngitoa.c \
	ft_pfnullcheck.c

LIBS = \
	libft/libft.a

INCLUDES = -Ilibft/includes -Iincludes/

OBJ_DIR = obj/


SRC_DIR = src/

all: $(NAME)

libft/libft.a:
	make -C libft/

#Création des fichiers .o
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

#Création du dossier OBJ_DIR
$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

#Compilation
$(NAME): libft/libft.a $(OBJ_DIR) $(OBJ)
	cp ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

#Compilation des fichiers .c en .o
$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(INCLUDES) -g3 -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

bonus: all

test : all
	cc main.c -g3 -c $(INCLUDES)
	cc main.o -L. -lftprintf

.PHONY = all clean fclean re test
