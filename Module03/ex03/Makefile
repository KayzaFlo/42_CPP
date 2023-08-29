# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 13:26:56 by fgeslin           #+#    #+#              #
#    Updated: 2023/07/25 12:27:16 by fgeslin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#####	CONFIG		############################################################
NAME		:= DiamondTrap
CC			:= c++
RM			:= rm -f
CFLAGS		= -Wall -Wextra -Werror -std=c++98

#####	SOURCES		############################################################
SRC			=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp \
				DiamondTrap.cpp
OBJ			=	$(SRC:.cpp=.o)

#####	Makefile  objs		###################################################
C_WHT		:= \033[0m
C_RED		:= \033[1;31m
C_GRE		:= \033[1;32m
C_YEL		:= \033[1;33m
C_CYA 		:= \033[1;36m

.cpp.o:
	@ echo "$(C_YEL)Compiling: $(C_WHT)$<"
	@ ${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

# ------ #

all: $(NAME)

$(NAME): $(OBJ)
	@ echo "$(C_GRE)Compilation ${C_WHT}of ${C_CYA}$(NAME) ${C_WHT}..."
	@ $(CC) -o $(NAME) $(OBJ)
	@ echo "$(C_CYA)$(NAME) $(C_GRE)created$(C_WHT) ✔️"

# ------ #

clean:
	@ ${RM} $(OBJ) $(OBJ_BONUS)
	@ echo "$(C_RED)Deleting $(C_CYA)$(NAME) $(C_WHT)objs ✔️"

fclean: clean
	@ ${RM} $(NAME)
	@ echo "$(C_RED)Deleting $(C_CYA)$(NAME) $(C_WHT)binary ✔️"

re: fclean all

.PHONY: all clean fclean re
