# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 13:01:16 by alde-abre         #+#    #+#              #
#    Updated: 2025/01/20 13:24:32 by alde-abr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = \
	ft_printf.c ft_printf_utils.c ft_displayhexa.c ft_displaynumbers.c \
	ft_displaychar.c

BONUS = \
	ft_printf_bonus.c ft_parseformat.c ft_pfbuildchar.c ft_pfbuildhexa.c \
	ft_pfbuildnb.c ft_pfbuildptr.c ft_pfbuildstr.c ft_unslngconvert_base.c \
	ft_pfbuildunsnb.c ft_unslngatoi_base.c ft_unslngconvert_base.c ft_unslngitoa.c \
	ft_pfnullcheck.c

LIBS = \
	bonus/libft/libft.a

INCLUDES = -I/bonus/libft/includes -I/bonus/includes/

MANDA_DIR = manda/

OBJ_DIR_BONUS = bonus/obj/

SRC_DIR_BONUS = bonus/src/

all: $(NAME)

bonus/libft/libft.a:
	make -C bonus/libft/

#Création des fichiers .o
OBJ = $(addprefix $(MANDA_DIR), $(SRC:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR_BONUS), $(BONUS:.c=.o))

#Création du dossier OBJ_DIR
$(OBJ_DIR_BONUS) :
	mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS)

#Compilation
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

#Compilation des fichiers .c en .o
%.o : %.c
	$(CC) $(INCLUDES) -c $< -o $@

$(OBJ_DIR_BONUS)%.o : $(SRC_DIR_BONUS)%.c
	$(CC) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	make clean -C bonus/libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C bonus/libft/

re: fclean all

bonus : bonus/libft/libft.a $(OBJ_DIR_BONUS) $(OBJ_BONUS)
	cp ./bonus/libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ_BONUS)


test : all
	cc main.c -g3 -c $(INCLUDES)
	cc main.o -L. -lftprintf

.PHONY = all clean fclean re test bonus
