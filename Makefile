# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 13:01:16 by alde-abre         #+#    #+#              #
#    Updated: 2025/01/23 19:56:17 by alde-abr         ###   ########.fr        #
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
	ft_pfbuildnb.c ft_pfbuildptr.c ft_pfbuildstr.c ft_pfnullcheck.c \
	ft_pfbuildunsnb.c ft_ui64atoi_base.c ft_ui64convert_base.c ft_ui64itoa.c


LIBS = \
	bonus/libft/libft.a

MANDA_INCLUDES = -Imanda/
BONUS_INCLUDES = -Ibonus/ -Ibonus/libft/includes

MANDA_DIR = manda/
BONUS_DIR = bonus/

all: $(NAME)

bonus/libft/libft.a:
	make -C bonus/libft/

#Création des fichiers .o
OBJ = $(addprefix $(MANDA_DIR), $(SRC:.c=.o))
OBJ_BONUS = $(addprefix $(BONUS_DIR), $(BONUS:.c=.o))

#Compilation
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

#Compilation des fichiers .c en .o
%.o : %.c
	$(CC) $(MANDA_INCLUDES) -c $< -o $@

$(BONUS_DIR)%.o : $(BONUS_DIR)%.c
	$(CC) $(BONUS_INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	make clean -C bonus/libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C bonus/libft/

re: fclean all

bonus : bonus/libft/libft.a $(OBJ_BONUS)
	cp ./bonus/libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ_BONUS)


test : all
	cc main.c -g3 -c $(MANDA_INCLUDES) $(BONUS_INCLUDES)
	cc main.o -L. -lftprintf

.PHONY = all clean fclean re test bonus
